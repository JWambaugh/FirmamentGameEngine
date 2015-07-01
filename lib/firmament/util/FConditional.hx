
package firmament.util;

import firmament.component.base.FEntityComponent;
import firmament.core.FComponent;
import firmament.core.FConfig;
import firmament.core.FEntity;
import firmament.core.FProperty;
import firmament.scene.FScene;
import firmament.scene.FSceneComponent;
import firmament.util.FLog;
import haxe.PosInfos;

class FConditional {

	private var _config:FConfig;
	private var _context:FComponent;
	private var _syntax = ~/([^\s<=>]+)\s*(!=|==|<=|>=|<|>)?\s*([^\s<=>]+)?/;
	private var _source:Dynamic; // or entity or scene?

	public function new ( config:FConfig, context:FComponent ) {
		_context = context;
		_config = config;
		if( _config != null ) {
			FLog.debug(Std.string(_config));
			_config.setScope( _context ); // makes sure that scripts work properly
		}
	}

	private function log(message:String,?force:Bool=false,?pos:PosInfos) {
		try{
			_context.log(message,force,pos);
		} catch(e:Dynamic) {
			trace(e);
		}
	}

	public function evaluate( name:String, ?source:Dynamic = null ):Bool {
		var result:Bool = true;
		if( _config != null && _config.hasField( name ) ) {
			_source = source; // this is temporary
			try {
				var expression:String = _config.getNotNull( name, String );
				_syntax.match(expression);
				log("Evaluating - " + name + " -> " + _syntax.matched(1) + (_syntax.matched(2)!=null?_syntax.matched(2) : "") + (_syntax.matched(3)!=null?_syntax.matched(3) : "") );
			    result = this.test( 
		    				  _syntax.matched(1), 
		    				( _syntax.matched(2) != null ? _syntax.matched(2) : "==" ), 
		    				( _syntax.matched(3) != null ? _syntax.matched(3) : true ) 
			    		);
			} catch( exception:Dynamic) {
				result = true; // allows pass through when no conditional exists
				FLog.debug( "Exception: " + Std.string(exception) );
			}
			_source = null;
		}
		return result;
	}

	private function test( clause1:Null<Dynamic>, conditional:String, clause2:Null<Dynamic>):Bool {
		var result:Bool = true;
		var eval1 = this.evaluateClause(clause1);
		var eval2 = this.evaluateClause(clause2);
		switch( conditional ) {
			case "==": result = (eval1 == eval2);
			case "!=": result = (eval1 != eval2);
			case "<=": result = (eval1 <= eval2);
			case ">=": result = (eval1 >= eval2);
			case ">": result = (eval1 > eval2);
			case "<": result = (eval1 < eval2);
			default: trace("Unsupported conditional type " + conditional);
		}
		log( "condition -> " + eval1 + conditional + eval2 + " -> " + Std.string(result) );
		return result;
	}

	private function evaluateClause ( value:Dynamic ):Dynamic {
		var result:Dynamic = value;
		if(Std.is(value,String)){
			var testValue:Dynamic;
			var strVal:String = StringTools.trim( cast value ); // trim spaces 
			var not:Bool = (strVal.substr(0,1) == '!'); // check for not
			if( not ) {
				strVal = strVal.substring(1);
			}
			if(strVal.indexOf("@this.")==0) {
				var propertyKey = strVal.substr(6);
				if(Std.is( _context,FEntityComponent) ) {
					var c:FEntityComponent = cast _context;
					result = c.getEntity().getProp(propertyKey);
				} else if(Std.is( _context,FSceneComponent) ) {
					var c:FSceneComponent = cast _context;
					result = c.getScene().getPropertyValue(propertyKey);
				}
			} else if ( strVal.indexOf("@")==0) {
				if( _source == null ) {
					log("Error: Conditional is comparing an entity that is not set! " + value );
					throw "Error - invalid object in conditional";
				}
				var propertyKey = strVal.substr(5);
				if(Std.is( _source,FEntity) ) {
					var c:FEntity = cast _source;
					result = c.getProp(propertyKey);
				} else if(Std.is(_source,FScene) ) {
					var c:FScene = cast _source;
					result = c.getPropertyValue(propertyKey);
				}
			} else {
				testValue = Std.parseInt(strVal);
				if( testValue != null ) {
					result = testValue;
				} else {
					testValue = Std.parseFloat(strVal);
					if( Math.isNaN(testValue) != true ) {
						result = testValue;
					} else {
						testValue = strVal.toLowerCase();
						if( testValue == "true" ) {
							result = true;
						} else if( testValue == "false" ) {
							result = false;
						}
					}
				}
			}
			result = (not ? (! result) : result );
		}
		return result;
	}
}

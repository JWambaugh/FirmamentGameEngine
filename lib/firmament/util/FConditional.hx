
package firmament.util;

import firmament.component.base.FEntityComponent;
import firmament.core.FComponent;
import firmament.core.FConfig;
import firmament.core.FProperty;
import firmament.scene.FSceneComponent;

class FConditional {

	private var _config:FConfig;
	private var _context:FComponent;
	private var _syntax = ~/([^\s<=>]+)\s*([!<=>]{2})?\s*([^\s<=>]+)?/;

	public function new ( config:FConfig, context:FComponent ) {
		_config = config;
		_context = context;
		_config.setScope( _context ); // makes sure that scripts work properly
	}

	public function evaluate( name:String ):Bool {
		var result:Bool = true;
		try {
			var expression:String = _config.getNotNull( name, String );
			// trace(name);
			// trace(expression);
			// expressions
			// prop|Int|Float cond prop|Int|Float
			_syntax.match(expression);
			// trace( Std.string(_syntax.matched(0)) );
		    result = this.test(   _syntax.matched(1), 
		    					( _syntax.matched(2) != null ? _syntax.matched(2) : "==" ), 
		    					( _syntax.matched(3) != null ? _syntax.matched(3) : true ) );
		} catch( exception:Dynamic) {
			result = true; // allows pass through when no conditional exists
		}
		return result;
	}

	private function test( clause1:Null<Dynamic>, conditional:String, clause2:Null<Dynamic>):Bool {
		var result:Bool = true;
		var eval1 = this.evaluateClause(clause1);
		var eval2 = this.evaluateClause(clause2);
		// trace(eval1,conditional,eval2);
		switch( conditional ) {
			case "==": result = (eval1 == eval2);
			case "!=": result = (eval1 != eval2);
			case "<=": result = (eval1 <= eval2);
			case ">=": result = (eval1 >= eval2);
			case ">": result = (eval1 > eval2);
			case "<": result = (eval1 < eval2);
		}
		// trace("Evaluated - " + result);
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
			if(strVal.indexOf("@")==0) {
				var propertyKey = strVal.substr(1);
				if(Std.is( _context,FEntityComponent) ) {
					var c:FEntityComponent = cast _context;
					result = c.getEntity().getProp(propertyKey);
				} else if(Std.is( _context,FSceneComponent) ) {
					var c:FSceneComponent = cast _context;
					result = c.getScene().getPropertyValue(propertyKey);
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
			// trace("Final " + result);
		}
		return result;
	}
}

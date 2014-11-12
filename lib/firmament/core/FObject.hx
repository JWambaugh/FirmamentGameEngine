package firmament.core;

import firmament.util.FLog;

import firmament.core.FEvent;
typedef FObjectConnection={
	listeningObject:FObject
	,callback:FEvent->Void
}
class FObject{

	private var __listeners:Map<String,List<FObjectConnection>>;

	public static inline var DESTRUCTED = "destructed";
	public function new(){
		__listeners = new Map();
	}

	public function on(target:FObject=null,eventName:String, listeningObject:FObject=null, callback:Dynamic->Void){
		//if target is not this, call on on the target, otherwise add the listener to us
		if(target!=null&&target!=this){
			target.on(target, eventName, this, callback);
			return;
		}
		else{
			if(__listeners.get(eventName) == null){
				__listeners.set(eventName,new List<FObjectConnection>());
			}
			__listeners.get(eventName).push({listeningObject:listeningObject,callback:cast(callback)});
		}
	}

	public function trigger(event:FEvent){

        //if the event doesn't bubble and has been handled by another object already, then do nothing.
        if(event.bubbles == false && event.handled)return;
		var l = __listeners.get(event.name);
		if(l != null){
            event.handled = true; //default to event was handled by this object. Listener can set this to false to allow it to bubble further.
			for(connection in l){
				try {
                	connection.callback(event);
				} catch (e:Dynamic) {
					FLog.error( 
					  Std.string(event.name) + " -> "
					  + Std.string(connection) + "\n  " 
					  + Std.string(e)
					);
				}
			}
		}
	}


	public function removeEventListener(eventName:String=null,listeningObject:FObject=null,callback:Dynamic->Void=null){
		if(eventName!=null){
			if(callback != null || listeningObject!=null){
				_removeEventListenerFromList(__listeners.get(eventName),listeningObject,callback);
			}
			else{
				__listeners.set(eventName,new List<FObjectConnection>());
			}
		}else{
			for(l in __listeners){
				_removeEventListenerFromList(l,listeningObject,callback);
			}
		}
	}

	private function _removeEventListenerFromList(l:List<FObjectConnection>,listeningObject:FObject=null,callback:Dynamic->Void=null){
		if(l != null){
			var itemsToRemove:List<FObjectConnection> = new List();
			for(c in l){
				if(
					(callback==null || (callback!=null && c.callback == callback) ) 
				&& (listeningObject==null || (listeningObject!=null && c.listeningObject == listeningObject) )){
					itemsToRemove.push(c);
				}
			}
			while(itemsToRemove.length>0){
				var item = itemsToRemove.pop();
				firmament.util.FLog.debug("Removing listener with target of "+Type.getClassName(Type.getClass(item.listeningObject))+" From "+Type.getClassName(Type.getClass(this)));
				while(l.remove(item)){}
			}
			
		}
	}

	public function removeAllListeners(){
		__listeners = new Map();
	}

	public function destruct(){
		removeAllListeners();
		trigger(new FEvent(DESTRUCTED));
	}
}
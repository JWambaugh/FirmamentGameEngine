package firmament.core;

#if neko
    import neko.vm.Thread;
    import neko.vm.Mutex;
#elseif cpp
    import cpp.vm.Thread;
    import cpp.vm.Mutex;
#end

//cross-platform mutex so precompiler conditionals are not required all over the place. 
//Does nothing on platforms that don't support threading.
class FMutex  #if (neko || cpp) extends Mutex #end {


    public function new(){
        #if (neko || cpp) 
            super();
        #end
    }

    #if (!neko && !cpp) //only create these functions if not neko or cpp, in which case the mutex does nothing
    public function acquire(){
        //noop
    }

    public function release(){
        //noop
    }

    #end

}
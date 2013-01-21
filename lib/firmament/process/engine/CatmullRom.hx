
package firmament.process.engine;

import nme.geom.Point;
import firmament.core.FVector;

class CatmullRom
{
    private var ps:Array<FVector>; // = [];
    private var step:Int; // = [];
    private var position:Float;
    private var p0:FVector;
    private var p1:FVector;
    private var p2:FVector;
    private var p3:FVector;
    private var rate:Float;
    private var startOffset:FVector;
    private var endOffset:FVector;

    /*CatmullRom*/
    public function new (points:Array<FVector>,totalTime:Float)
    {
    	ps = [];

        step = -1;
        position = 1;

        var N:Int = Std.int(3 + 10 * Math.random ());
        for ( i in 0 ... N ) {
            ps.push (new FVector (200-400 * Math.random (), 200-400 * Math.random ()));
        }
        /*ps.push (new FVector (-200, -200));
        ps.push (new FVector (0,0));
        ps.push (new FVector (200, 200));*/
        rate = ps.length / 10.0;

        if(Std.is(points,Array)) {
            ps = [];
            for(point in points) {
                ps.push(point);
            }
        }

        if(Math.isNaN(totalTime) == false) {
            rate = ps.length / totalTime;
        }
    }

    public function setStartTarget() {

    }

    public function setEndTarget() {

    }

    public function reset() {
        step = -1;
        position = 1;
    }

    public function progress() {
        return step/(ps.length-1);
    }

    public function loop (delta:Float):FVector 
    {
        var updated:Bool = false;
        position=position+(delta*rate);
        while(position > 1) {
            updated=true;
            step = (step+1) % (ps.length-1);
            position=position-1;
        }

        if(updated) {
            var s0 = ((step-1)>=0)?step-1:0; var s1 = step;
            var s2=((step+1)<ps.length)?step+1:step; 
            var s3=((step+2)<ps.length)?step+2:step;
            p0 = ps [s0];
            p1 = ps [s1];
            p2 = ps [s2];
            p3 = ps [s3];
        }

        var q:FVector = spline (p0, p1, p2, p3, position);
        // trace("Points - " + q.x + "," + q.y);
        return q;
    }

    public function getPoints():Array<FVector> {
        return ps;
    }

    /* 
    * Calculates 2D cubic Catmull-Rom spline.
    * @see http://www.mvps.org/directx/articles/catmull/
    */ 
    public function spline (p0:FVector, p1:FVector, p2:FVector, p3:FVector, t:Float):FVector 
    {
        return new FVector (
            0.5 * ((          2*p1.x) +
                t * (( -p0.x           +p2.x) +
                t * ((2*p0.x -5*p1.x +4*p2.x -p3.x) +
                t * (  -p0.x +3*p1.x -3*p2.x +p3.x)))),
            0.5 * ((          2*p1.y) +
                t * (( -p0.y           +p2.y) +
                t * ((2*p0.y -5*p1.y +4*p2.y -p3.y) +
                t * (  -p0.y +3*p1.y -3*p2.y +p3.y))))
        );
    }
}
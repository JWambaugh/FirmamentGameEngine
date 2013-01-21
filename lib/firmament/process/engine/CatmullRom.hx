
package firmament.process.engine;

import nme.geom.Point;
import firmament.core.FCamera;

class CatmullRom
{
    private var ps:Array<Dynamic>; // = [];
    private var step:Int; // = [];
    private var position:Float;

    /*CatmullRom*/
    public function new ()
    {
    	ps = [];

        step = -1;
        position = 1;

        var N:Int = Std.int(3 + 1/*+ 10 * Math.random ()*/);
        /*for ( i in 0 ... N ) {
            ps.push (new Point (200-400 * Math.random (), 200-400 * Math.random ()));
        }*/

        ps.push (new Point (-200, -200));
        ps.push (new Point (0,0));
        ps.push (new Point (200, 200));
    }

    public function loop (delta:Float):Point 
    {
        position=position+delta;
        while(position > 1) {
            trace("Step: " + step);
            step = (step+1) % (ps.length-1);
            trace("Step: " + step);
            position=position-1;
        }

        trace("Step: " + step);
        trace("Position: " + position);

         // draw spline
        /*for (i in 0 ... ps.length)*/ {
            var s0 = ((step-1)>=0)?step-1:0; var s1 = step;
            var s2=((step+1)<ps.length)?step+1:step; 
            var s3=((step+2)<ps.length)?step+2:step;
            var p0:Point = ps [s0];
            var p1:Point = ps [s1];
            var p2:Point = ps [s2];
            var p3:Point = ps [s3];

            //s.graphics.moveTo (p1.x, p1.y);
            /*for ( j  in 1...101 ) { */
                var q:Point = spline (p0, p1, p2, p3, position);
                trace("Points - " + q.x + "," + q.y);
                //s.graphics.lineTo (q.x, q.y);
                // want to draw the tangent eventually
            /*}*/

            return q;

            /*if (counter++ > 0) {
                        camera.graphics.lineTo((pos.x+vec.x-cameraPos.x)*camera.getZoom(), (pos.y+vec.y-cameraPos.y)*camera.getZoom());
                    }
                    pvec = vec;
                    camera.graphics.moveTo(( pos.x+pvec.x - cameraPos.x)*camera.getZoom(), (pos.y+pvec.y - cameraPos.y)*camera.getZoom());
            */
        }
    }

    public function getPoints():Array<Dynamic> {
        return ps;
    }

    /* 
    * Calculates 2D cubic Catmull-Rom spline.
    * @see http://www.mvps.org/directx/articles/catmull/
    */ 
    public function spline (p0:Point, p1:Point, p2:Point, p3:Point, t:Float):Point 
    {
        return new Point (
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
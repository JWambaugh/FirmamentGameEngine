
package firmament.utils;
import firmament.core.FVector;


//ported from http://lostinactionscript.com/2007/07/11/douglas-peuker-line-generalization/
class FPolySimplifier {
	// 2D Vector functions
	private static function dot(u:FVector, v:FVector) {
		return ((u.x*v.x)+(u.y*v.y));
	}
	private static function norm2(v:FVector) {
		return dot(v, v);
	}
	private static function norm(v) {
		return Math.sqrt(norm2(v));
	}
	private static function d2(u:FVector, v:FVector) {
		return norm2(minusNew(u, v));
	}
	private static function d(u, v) {
		return norm(minusNew(u, v));
	}
	private static function addNew(v:FVector, a:FVector):FVector {
		return new FVector(v.x+a.x, v.y+a.x);
	}
	private static function multiNew(v:FVector, a:Float):FVector {
		return new FVector(v.x*a, v.y*a);
	}
	private static function minusNew(v:FVector, a:FVector):FVector {
		return new FVector((v.x-a.x), (v.y-a.y));
	}
	
	public static function simplify(pts:Array<FVector>, tol:Float, stages:Int=2):Array<FVector> {
		var pv:Int = 0;
		var n:Int = pts.length;
		var tol2:Float = tol*tol;
		var pts1:Array<FVector> = new Array<FVector>();
		var used:Array<Bool> = new Array<Bool>();
		// STAGE 1.  ptsertex Reduction within tolerance of prior vertex cluster
		pts1.push(pts[0]);
		var i = 1;
		while ( i<n ) {
			if (d2(pts[i], pts[pv]) < tol2) {
				i++;
				continue;
			}
			pts1.push(pts[i]);
			pv = i;
			i++;
		}
		if (pv<n-1) {
			pts1.push(pts[n-1]);
		}
		if (stages>1) {
			// STAGE 2.  Douglas-Peucker polyline simplification 
			used[0] = used[pts1.length-1]=true;
			simplifyDP(pts1, tol, 0, pts1.length-1, used);
			var pts2:Array<FVector> = new Array<FVector>();
			for (i in 0...used.length) {
				if (used[i]) {
					pts2.push(pts1[i]);
				}
			}
			return pts2;
		} else {
			return pts1;
		}
	}
	private static function simplifyDP(pts:Array<FVector>, tol:Float, start:Int, end:Int, used:Array<Bool>) {
		if (end<=start+1) {
			return;
		}
		//     
		var maxi:Int = start;
		var maxd2:Float = 0;
		var tol2:Float = tol*tol;
		var line:Array<FVector> = [pts[start], pts[end]];
		var u = minusNew(line[1], line[0]);
		var cu = dot(u, u);
		//
		for (i in start...end) {
			var w:FVector = minusNew(pts[i], line[0]);
			var cw:Float = dot(w, u);
			var dv2:Float;
			if (cw<=0) {
				dv2 = d2(pts[i], line[0]);
			} else if (cu<=cw) {
				dv2 = d2(pts[i], line[1]);
			} else {
				var b:Float = cw/cu;
				var Pb = addNew(line[0], multiNew(u, b));
				dv2 = d2(pts[i], Pb);
			}
			if (dv2<=maxd2) {
				continue;
			}
			maxi = i;
			maxd2 = dv2;
		}
		if (maxd2>tol2) {
			used[maxi] = true;
			simplifyDP(pts, tol, maxi, end, used);
			simplifyDP(pts, tol, start, maxi, used);
		}
		return;
	}
}

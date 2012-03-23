package firmament.core;

import firmament.core.FVector;

class FTriangulator 
{
	static inline var EPSILON:Float = 0.0000000001;
	static function area(contour:Array<FVector>)
	{
		var n = contour.length;
		var A=0.0;
		var p = n - 1;
		var q=0;
		while(q<n)
		{
			A += contour[p].x * contour[q].y - contour[q].x * contour[p].y;
			p = q++;
		}
		return A*0.5;
	}


	/**
	 * decides if a povar P is Inside of the triangle
	 * defined by A, B, C.
	 */
	static function insideTriangle(Ax:Float,Ay:Float,
							Bx:Float, By:Float,
							Cx:Float, Cy:Float,
							Px:Float, Py:Float){
		var ax:Float, ay:Float, bx:Float, by:Float, cx:Float, cy:Float, apx:Float, apy:Float, bpx:Float, bpy:Float, cpx:Float, cpy:Float;
		var cCROSSap:Float, bCROSScp:Float, aCROSSbp:Float;
		
		ax = Cx - Bx;  ay = Cy - By;
		bx = Ax - Cx;  by = Ay - Cy;
		cx = Bx - Ax;  cy = By - Ay;
		apx= Px - Ax;  apy= Py - Ay;
		bpx= Px - Bx;  bpy= Py - By;
		cpx= Px - Cx;  cpy= Py - Cy;
		
		aCROSSbp = ax*bpy - ay*bpx;
		cCROSSap = cx*apy - cy*apx;
		bCROSScp = bx*cpy - by*cpx;
		
		return ((aCROSSbp >= 0.0) && (bCROSScp >= 0.0) && (cCROSSap >= 0.0));
	}
		
		
	static function snip (contour:Array<FVector>, u, v, w, n,V)
	{
		var p:Int;
		var Ax, Ay, Bx, By, Cx, Cy, Px, Py;

		Ax = contour[V[u]].x;
		Ay = contour[V[u]].y;

		Bx = contour[V[v]].x;
		By = contour[V[v]].y;

		Cx = contour[V[w]].x;
		Cy = contour[V[w]].y;

		if ( FTriangulator.EPSILON > (((Bx-Ax)*(Cy-Ay)) - ((By-Ay)*(Cx-Ax))) ) return false;
		p=0;
		while (p<n)
		{
			if ( (p == u) || (p == v) || (p == w) ) { p++; continue;}
			Px = contour[V[p]].x;
			Py = contour[V[p]].y;
			if (FTriangulator.insideTriangle(Ax, Ay, Bx, By, Cx, Cy, Px, Py)) return false;
			p++;
		}

		return true;
	}
	static function process(contour:Array<FVector>,result:Array<FVector>)
	{
	/* allocate and initialize list of Vertices in polygon */

	var n:Int = contour.length;
	if ( n < 3 ) return false;

	var V:Array<Int> = new Array<Int> ();

	/* we want a counter-clockwise polygon in V */

	if ( 0.0 < FTriangulator.area(contour) )
		for (v in 0 ... n) V[v] = v;
	else
		for(v in 0 ... n) V[v] = (n-1)-v;

	var nv:Int = n;

	/*  remove nv-2 Vertices, creating 1 triangle every time */
	var count = 2*nv;   /* error detection */
	var m = 0;
	var v = nv - 1;
	while( nv>2 )
	{
		/* if we loop, it is probably a non-simple polygon */
		if (0 >= (count--))
		{
		  //** Triangulate: ERROR - probable bad polygon!
		  
		  return false;
		}

		/* three consecutive vertices in current polygon, <u,v,w> */
		var u = v  ; if (nv <= u) u = 0;     /* previous */
		v = u+1; if (nv <= v) v = 0;     /* new v    */
		var w = v+1; if (nv <= w) w = 0;     /* next     */

		if ( FTriangulator.snip(contour,u,v,w,nv,V) )
		{
			var a,b,c,s,t;

			/* true names of the vertices */
			a = V[u]; b = V[v]; c = V[w];

			/* output Triangle */
			result.push( contour[a] );
			result.push( contour[b] );
			result.push( contour[c] );
			m++;
			/* remove v from remaining polygon */
			s = v;
			t = v + 1;
			while ( t < nv) {
				V[s] = V[t]; 
			    s++; t++;
			}
			nv--;
			/* resest error detection counter */
			count = 2*nv;
		}
	}



	  //delete V;

	  return true;
	}
	
	public static function getTriangles(shape:Array<FVector>):Array<Array<FVector>>{
		var res:Array<FVector> = new Array<FVector>();
		var triangles:Array<Array<FVector>> = new Array<Array<FVector>>();
		if (!FTriangulator.process(shape, res)) {
			
			return null;
		}
		trace(res.length);
		var triangleCount:Int = Math.floor(res.length/3);
		for(x in 0...triangleCount){
			triangles.push(
			[
			 res[x*3]
			 ,res[x*3+1]
			 ,res[x*3+2]
			 ]		
			);
		}
		return triangles;
	}
		
		
}

	

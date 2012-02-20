package com.firmamentengine.firmament;
import com.firmamentengine.firmament.FEntity;
/**
 * ...
 * @author Jordan Wambaugh
 */

class FWorld 
{
	
	var entities:Array<FEntity>;
	public function new() 
	{
		
	}
	public function addEntity(ent:FEntity) {
		this.entities.push(ent);
		
	}
	
	public function getAllEntities():Array<FEntity> {
		return this.entities;
	}
	
	public function step() {
	}
	
	
	
}
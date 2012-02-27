#include <hxcpp.h>

#include <nme/display/BitmapData.h>
#include <box2D/collision/B2ContactID.h>
#include <nme/events/Listener.h>
#include <com/firmamentengine/firmament/FGame.h>
#include <box2D/common/math/B2Mat33.h>
#include <nme/display/CapsStyle.h>
#include <nme/geom/Transform.h>
#include <box2D/dynamics/joints/B2LineJoint.h>
#include <box2D/dynamics/B2DebugDraw.h>
#include <box2D/dynamics/contacts/B2PolyAndEdgeContact.h>
#include <nme/errors/EOFError.h>
#include <box2D/dynamics/joints/B2PrismaticJoint.h>
#include <com/firmamentengine/firmament/FVector.h>
#include <nme/display/InterpolationMethod.h>
#include <box2D/collision/shapes/B2PolygonShape.h>
#include <nme/utils/ByteArray.h>
#include <box2D/dynamics/joints/B2FrictionJoint.h>
#include <box2D/collision/B2SimplexVertex.h>
#include <nme/display/PixelSnapping.h>
#include <nme/events/FocusEvent.h>
#include <haxe/io/Error.h>
#include <nme/media/SoundChannel.h>
#include <cpp/Sys.h>
#include <box2D/collision/shapes/B2CircleShape.h>
#include <box2D/dynamics/B2DestructionListener.h>
#include <box2D/dynamics/joints/B2WeldJointDef.h>
#include <box2D/dynamics/contacts/B2ContactRegister.h>
#include <box2D/dynamics/joints/B2Jacobian.h>
#include <nme/errors/RangeError.h>
#include <cpp/zip/Uncompress.h>
#include <nme/events/EventPhase.h>
#include <box2D/collision/B2DynamicTree.h>
#include <nme/filters/BitmapFilter.h>
#include <haxe/Timer.h>
#include <box2D/collision/B2AABB.h>
#include <Std.h>
#include <nme/media/SoundTransform.h>
#include <nme/display/MovieClip.h>
#include <nme/display/LineScaleMode.h>
#include <nme/display/TriangleCulling.h>
#include <nme/utils/WeakRef.h>
#include <nme/geom/Matrix.h>
#include <cpp/rtti/FieldNumericIntegerLookup.h>
#include <box2D/dynamics/contacts/B2ContactSolver.h>
#include <box2D/collision/B2WorldManifold.h>
#include <nme/display/StageScaleMode.h>
#include <nme/display/Bitmap.h>
#include <ApplicationMain.h>
#include <box2D/dynamics/controllers/B2Controller.h>
#include <box2D/dynamics/contacts/B2ContactConstraint.h>
#include <box2D/dynamics/contacts/B2EdgeAndCircleContact.h>
#include <nme/utils/Endian.h>
#include <nme/events/KeyboardEvent.h>
#include <box2D/collision/B2RayCastInput.h>
#include <nme/events/TimerEvent.h>
#include <nme/net/URLLoader.h>
#include <nme/display/SpreadMethod.h>
#include <box2D/collision/B2TimeOfImpact.h>
#include <box2D/collision/B2DistanceInput.h>
#include <box2D/dynamics/B2BodyDef.h>
#include <box2D/dynamics/B2Fixture.h>
#include <haxe/Log.h>
#include <box2D/collision/B2DynamicTreePair.h>
#include <com/firmamentengine/firmament/FPhysicsEntity.h>
#include <com/firmamentengine/firmament/FEntity.h>
#include <com/firmamentengine/firmament/FRenderable.h>
#include <box2D/collision/B2DynamicTreeNode.h>
#include <StringBuf.h>
#include <nme/display/Tilesheet.h>
#include <box2D/collision/Features.h>
#include <box2D/collision/B2DistanceOutput.h>
#include <nme/display/StageAlign.h>
#include <nme/display/ManagedStage.h>
#include <com/firmamentengine/firmament/Main.h>
#include <box2D/dynamics/contacts/B2ContactFactory.h>
#include <box2D/dynamics/joints/B2PrismaticJointDef.h>
#include <box2D/collision/B2DynamicTreeBroadPhase.h>
#include <box2D/collision/IBroadPhase.h>
#include <box2D/dynamics/joints/B2GearJoint.h>
#include <nme/geom/ColorTransform.h>
#include <haxe/io/Eof.h>
#include <nme/utils/IDataInput.h>
#include <nme/events/JoystickEvent.h>
#include <box2D/collision/shapes/B2MassData.h>
#include <Date.h>
#include <box2D/dynamics/joints/B2DistanceJoint.h>
#include <nme/utils/Timer.h>
#include <box2D/dynamics/B2ContactListener.h>
#include <nme/Lib.h>
#include <box2D/dynamics/contacts/B2ContactConstraintPoint.h>
#include <box2D/collision/B2Collision.h>
#include <nme/display/IGraphicsData.h>
#include <com/firmamentengine/firmament/FCamera.h>
#include <com/firmamentengine/firmament/FWorldPositionalInterface.h>
#include <nme/display/Sprite.h>
#include <box2D/dynamics/joints/B2LineJointDef.h>
#include <com/firmamentengine/firmament/FPhysicsWorld.h>
#include <box2D/dynamics/joints/B2GearJointDef.h>
#include <box2D/collision/B2ManifoldPoint.h>
#include <box2D/dynamics/joints/B2MouseJoint.h>
#include <box2D/dynamics/joints/B2PulleyJoint.h>
#include <box2D/dynamics/contacts/B2CircleContact.h>
#include <cpp/io/FileInput.h>
#include <Reflect.h>
#include <nme/display/JointStyle.h>
#include <box2D/dynamics/joints/B2FrictionJointDef.h>
#include <box2D/dynamics/joints/B2RevoluteJoint.h>
#include <box2D/collision/B2SimplexCache.h>
#include <nme/events/IOErrorEvent.h>
#include <nme/events/ErrorEvent.h>
#include <nme/events/TextEvent.h>
#include <com/firmamentengine/firmament/FWorldPositional.h>
#include <box2D/common/math/B2Math.h>
#include <nme/errors/Error.h>
#include <Type.h>
#include <ValueType.h>
#include <nme/display/BlendMode.h>
#include <cpp/zip/Flush.h>
#include <cpp/io/File.h>
#include <cpp/io/FileSeek.h>
#include <box2D/dynamics/B2ContactManager.h>
#include <box2D/collision/B2ContactPoint.h>
#include <box2D/dynamics/joints/B2WeldJoint.h>
#include <box2D/dynamics/joints/B2Joint.h>
#include <nme/geom/Rectangle.h>
#include <box2D/collision/B2Distance.h>
#include <box2D/collision/B2Simplex.h>
#include <box2D/collision/B2DistanceProxy.h>
#include <box2D/collision/B2Manifold.h>
#include <box2D/dynamics/B2FilterData.h>
#include <nme/net/URLVariables.h>
#include <com/firmamentengine/firmament/FWorld.h>
#include <box2D/collision/B2RayCastOutput.h>
#include <nme/display/StageQuality.h>
#include <box2D/collision/ClipVertex.h>
#include <box2D/dynamics/joints/B2DistanceJointDef.h>
#include <box2D/common/math/B2Vec3.h>
#include <box2D/collision/B2SeparationFunction.h>
#include <box2D/common/B2Settings.h>
#include <cpp/io/FileOutput.h>
#include <box2D/dynamics/joints/B2RevoluteJointDef.h>
#include <nme/display/Graphics.h>
#include <box2D/dynamics/joints/B2PulleyJointDef.h>
#include <cpp/FileSystem.h>
#include <cpp/FileKind.h>
#include <nme/display/TouchInfo.h>
#include <nme/display/Stage.h>
#include <nme/display/DisplayObjectContainer.h>
#include <nme/display/InteractiveObject.h>
#include <nme/display/DisplayObject.h>
#include <nme/Loader.h>
#include <nme/display/IBitmapDrawable.h>
#include <nme/events/EventDispatcher.h>
#include <nme/events/IEventDispatcher.h>
#include <box2D/dynamics/B2World.h>
#include <box2D/dynamics/B2TimeStep.h>
#include <box2D/common/B2Color.h>
#include <box2D/common/math/B2Sweep.h>
#include <box2D/dynamics/contacts/B2PolygonContact.h>
#include <com/firmamentengine/firmament/FWireframeRenderer.h>
#include <com/firmamentengine/firmament/FRenderer.h>
#include <haxe/io/BytesBuffer.h>
#include <box2D/collision/B2OBB.h>
#include <box2D/dynamics/contacts/B2ContactEdge.h>
#include <haxe/io/Bytes.h>
#include <StringTools.h>
#include <cpp/zip/Compress.h>
#include <box2D/dynamics/controllers/B2ControllerEdge.h>
#include <nme/net/URLRequest.h>
#include <box2D/dynamics/B2FixtureDef.h>
#include <box2D/dynamics/B2ContactFilter.h>
#include <IntHash.h>
#include <nme/display/GradientType.h>
#include <Hash.h>
#include <nme/net/URLRequestMethod.h>
#include <cpp/io/Process.h>
#include <cpp/io/_Process/Stdout.h>
#include <haxe/io/Input.h>
#include <cpp/io/_Process/Stdin.h>
#include <haxe/io/Output.h>
#include <cpp/Lib.h>
#include <IntIter.h>
#include <box2D/collision/shapes/B2EdgeShape.h>
#include <box2D/collision/shapes/B2Shape.h>
#include <nme/geom/Point.h>
#include <box2D/dynamics/joints/B2JointEdge.h>
#include <List.h>
#include <box2D/dynamics/joints/B2MouseJointDef.h>
#include <box2D/dynamics/joints/B2JointDef.h>
#include <nme/net/URLLoaderDataFormat.h>
#include <box2D/dynamics/B2Body.h>
#include <box2D/common/math/B2Transform.h>
#include <box2D/dynamics/contacts/B2PositionSolverManifold.h>
#include <box2D/common/math/B2Vec2.h>
#include <box2D/dynamics/B2Island.h>
#include <box2D/dynamics/B2ContactImpulse.h>
#include <box2D/common/math/B2Mat22.h>
#include <nme/events/ProgressEvent.h>
#include <nme/display/StageDisplayState.h>
#include <box2D/dynamics/contacts/B2PolyAndCircleContact.h>
#include <box2D/dynamics/contacts/B2Contact.h>
#include <box2D/collision/B2TOIInput.h>
#include <nme/events/TouchEvent.h>
#include <nme/events/MouseEvent.h>
#include <nme/events/Event.h>

void __boot_all()
{
hx::RegisterResources( hx::GetResources() );
::nme::display::BitmapData_obj::__register();
::box2D::collision::B2ContactID_obj::__register();
::nme::events::Listener_obj::__register();
::com::firmamentengine::firmament::FGame_obj::__register();
::box2D::common::math::B2Mat33_obj::__register();
::nme::display::CapsStyle_obj::__register();
::nme::geom::Transform_obj::__register();
::box2D::dynamics::joints::B2LineJoint_obj::__register();
::box2D::dynamics::B2DebugDraw_obj::__register();
::box2D::dynamics::contacts::B2PolyAndEdgeContact_obj::__register();
::nme::errors::EOFError_obj::__register();
::box2D::dynamics::joints::B2PrismaticJoint_obj::__register();
::com::firmamentengine::firmament::FVector_obj::__register();
::nme::display::InterpolationMethod_obj::__register();
::box2D::collision::shapes::B2PolygonShape_obj::__register();
::nme::utils::ByteArray_obj::__register();
::box2D::dynamics::joints::B2FrictionJoint_obj::__register();
::box2D::collision::B2SimplexVertex_obj::__register();
::nme::display::PixelSnapping_obj::__register();
::nme::events::FocusEvent_obj::__register();
::haxe::io::Error_obj::__register();
::nme::media::SoundChannel_obj::__register();
::cpp::Sys_obj::__register();
::box2D::collision::shapes::B2CircleShape_obj::__register();
::box2D::dynamics::B2DestructionListener_obj::__register();
::box2D::dynamics::joints::B2WeldJointDef_obj::__register();
::box2D::dynamics::contacts::B2ContactRegister_obj::__register();
::box2D::dynamics::joints::B2Jacobian_obj::__register();
::nme::errors::RangeError_obj::__register();
::cpp::zip::Uncompress_obj::__register();
::nme::events::EventPhase_obj::__register();
::box2D::collision::B2DynamicTree_obj::__register();
::nme::filters::BitmapFilter_obj::__register();
::haxe::Timer_obj::__register();
::box2D::collision::B2AABB_obj::__register();
::Std_obj::__register();
::nme::media::SoundTransform_obj::__register();
::nme::display::MovieClip_obj::__register();
::nme::display::LineScaleMode_obj::__register();
::nme::display::TriangleCulling_obj::__register();
::nme::utils::WeakRef_obj::__register();
::nme::geom::Matrix_obj::__register();
::cpp::rtti::FieldNumericIntegerLookup_obj::__register();
::box2D::dynamics::contacts::B2ContactSolver_obj::__register();
::box2D::collision::B2WorldManifold_obj::__register();
::nme::display::StageScaleMode_obj::__register();
::nme::display::Bitmap_obj::__register();
::ApplicationMain_obj::__register();
::box2D::dynamics::controllers::B2Controller_obj::__register();
::box2D::dynamics::contacts::B2ContactConstraint_obj::__register();
::box2D::dynamics::contacts::B2EdgeAndCircleContact_obj::__register();
::nme::utils::Endian_obj::__register();
::nme::events::KeyboardEvent_obj::__register();
::box2D::collision::B2RayCastInput_obj::__register();
::nme::events::TimerEvent_obj::__register();
::nme::net::URLLoader_obj::__register();
::nme::display::SpreadMethod_obj::__register();
::box2D::collision::B2TimeOfImpact_obj::__register();
::box2D::collision::B2DistanceInput_obj::__register();
::box2D::dynamics::B2BodyDef_obj::__register();
::box2D::dynamics::B2Fixture_obj::__register();
::haxe::Log_obj::__register();
::box2D::collision::B2DynamicTreePair_obj::__register();
::com::firmamentengine::firmament::FPhysicsEntity_obj::__register();
::com::firmamentengine::firmament::FEntity_obj::__register();
::com::firmamentengine::firmament::FRenderable_obj::__register();
::box2D::collision::B2DynamicTreeNode_obj::__register();
::StringBuf_obj::__register();
::nme::display::Tilesheet_obj::__register();
::box2D::collision::Features_obj::__register();
::box2D::collision::B2DistanceOutput_obj::__register();
::nme::display::StageAlign_obj::__register();
::nme::display::ManagedStage_obj::__register();
::com::firmamentengine::firmament::Main_obj::__register();
::box2D::dynamics::contacts::B2ContactFactory_obj::__register();
::box2D::dynamics::joints::B2PrismaticJointDef_obj::__register();
::box2D::collision::B2DynamicTreeBroadPhase_obj::__register();
::box2D::collision::IBroadPhase_obj::__register();
::box2D::dynamics::joints::B2GearJoint_obj::__register();
::nme::geom::ColorTransform_obj::__register();
::haxe::io::Eof_obj::__register();
::nme::utils::IDataInput_obj::__register();
::nme::events::JoystickEvent_obj::__register();
::box2D::collision::shapes::B2MassData_obj::__register();
::Date_obj::__register();
::box2D::dynamics::joints::B2DistanceJoint_obj::__register();
::nme::utils::Timer_obj::__register();
::box2D::dynamics::B2ContactListener_obj::__register();
::nme::Lib_obj::__register();
::box2D::dynamics::contacts::B2ContactConstraintPoint_obj::__register();
::box2D::collision::B2Collision_obj::__register();
::nme::display::IGraphicsData_obj::__register();
::com::firmamentengine::firmament::FCamera_obj::__register();
::com::firmamentengine::firmament::FWorldPositionalInterface_obj::__register();
::nme::display::Sprite_obj::__register();
::box2D::dynamics::joints::B2LineJointDef_obj::__register();
::com::firmamentengine::firmament::FPhysicsWorld_obj::__register();
::box2D::dynamics::joints::B2GearJointDef_obj::__register();
::box2D::collision::B2ManifoldPoint_obj::__register();
::box2D::dynamics::joints::B2MouseJoint_obj::__register();
::box2D::dynamics::joints::B2PulleyJoint_obj::__register();
::box2D::dynamics::contacts::B2CircleContact_obj::__register();
::cpp::io::FileInput_obj::__register();
::Reflect_obj::__register();
::nme::display::JointStyle_obj::__register();
::box2D::dynamics::joints::B2FrictionJointDef_obj::__register();
::box2D::dynamics::joints::B2RevoluteJoint_obj::__register();
::box2D::collision::B2SimplexCache_obj::__register();
::nme::events::IOErrorEvent_obj::__register();
::nme::events::ErrorEvent_obj::__register();
::nme::events::TextEvent_obj::__register();
::com::firmamentengine::firmament::FWorldPositional_obj::__register();
::box2D::common::math::B2Math_obj::__register();
::nme::errors::Error_obj::__register();
::Type_obj::__register();
::ValueType_obj::__register();
::nme::display::BlendMode_obj::__register();
::cpp::zip::Flush_obj::__register();
::cpp::io::File_obj::__register();
::cpp::io::FileSeek_obj::__register();
::box2D::dynamics::B2ContactManager_obj::__register();
::box2D::collision::B2ContactPoint_obj::__register();
::box2D::dynamics::joints::B2WeldJoint_obj::__register();
::box2D::dynamics::joints::B2Joint_obj::__register();
::nme::geom::Rectangle_obj::__register();
::box2D::collision::B2Distance_obj::__register();
::box2D::collision::B2Simplex_obj::__register();
::box2D::collision::B2DistanceProxy_obj::__register();
::box2D::collision::B2Manifold_obj::__register();
::box2D::dynamics::B2FilterData_obj::__register();
::nme::net::URLVariables_obj::__register();
::com::firmamentengine::firmament::FWorld_obj::__register();
::box2D::collision::B2RayCastOutput_obj::__register();
::nme::display::StageQuality_obj::__register();
::box2D::collision::ClipVertex_obj::__register();
::box2D::dynamics::joints::B2DistanceJointDef_obj::__register();
::box2D::common::math::B2Vec3_obj::__register();
::box2D::collision::B2SeparationFunction_obj::__register();
::box2D::common::B2Settings_obj::__register();
::cpp::io::FileOutput_obj::__register();
::box2D::dynamics::joints::B2RevoluteJointDef_obj::__register();
::nme::display::Graphics_obj::__register();
::box2D::dynamics::joints::B2PulleyJointDef_obj::__register();
::cpp::FileSystem_obj::__register();
::cpp::FileKind_obj::__register();
::nme::display::TouchInfo_obj::__register();
::nme::display::Stage_obj::__register();
::nme::display::DisplayObjectContainer_obj::__register();
::nme::display::InteractiveObject_obj::__register();
::nme::display::DisplayObject_obj::__register();
::nme::Loader_obj::__register();
::nme::display::IBitmapDrawable_obj::__register();
::nme::events::EventDispatcher_obj::__register();
::nme::events::IEventDispatcher_obj::__register();
::box2D::dynamics::B2World_obj::__register();
::box2D::dynamics::B2TimeStep_obj::__register();
::box2D::common::B2Color_obj::__register();
::box2D::common::math::B2Sweep_obj::__register();
::box2D::dynamics::contacts::B2PolygonContact_obj::__register();
::com::firmamentengine::firmament::FWireframeRenderer_obj::__register();
::com::firmamentengine::firmament::FRenderer_obj::__register();
::haxe::io::BytesBuffer_obj::__register();
::box2D::collision::B2OBB_obj::__register();
::box2D::dynamics::contacts::B2ContactEdge_obj::__register();
::haxe::io::Bytes_obj::__register();
::StringTools_obj::__register();
::cpp::zip::Compress_obj::__register();
::box2D::dynamics::controllers::B2ControllerEdge_obj::__register();
::nme::net::URLRequest_obj::__register();
::box2D::dynamics::B2FixtureDef_obj::__register();
::box2D::dynamics::B2ContactFilter_obj::__register();
::IntHash_obj::__register();
::nme::display::GradientType_obj::__register();
::Hash_obj::__register();
::nme::net::URLRequestMethod_obj::__register();
::cpp::io::Process_obj::__register();
::cpp::io::_Process::Stdout_obj::__register();
::haxe::io::Input_obj::__register();
::cpp::io::_Process::Stdin_obj::__register();
::haxe::io::Output_obj::__register();
::cpp::Lib_obj::__register();
::IntIter_obj::__register();
::box2D::collision::shapes::B2EdgeShape_obj::__register();
::box2D::collision::shapes::B2Shape_obj::__register();
::nme::geom::Point_obj::__register();
::box2D::dynamics::joints::B2JointEdge_obj::__register();
::List_obj::__register();
::box2D::dynamics::joints::B2MouseJointDef_obj::__register();
::box2D::dynamics::joints::B2JointDef_obj::__register();
::nme::net::URLLoaderDataFormat_obj::__register();
::box2D::dynamics::B2Body_obj::__register();
::box2D::common::math::B2Transform_obj::__register();
::box2D::dynamics::contacts::B2PositionSolverManifold_obj::__register();
::box2D::common::math::B2Vec2_obj::__register();
::box2D::dynamics::B2Island_obj::__register();
::box2D::dynamics::B2ContactImpulse_obj::__register();
::box2D::common::math::B2Mat22_obj::__register();
::nme::events::ProgressEvent_obj::__register();
::nme::display::StageDisplayState_obj::__register();
::box2D::dynamics::contacts::B2PolyAndCircleContact_obj::__register();
::box2D::dynamics::contacts::B2Contact_obj::__register();
::box2D::collision::B2TOIInput_obj::__register();
::nme::events::TouchEvent_obj::__register();
::nme::events::MouseEvent_obj::__register();
::nme::events::Event_obj::__register();
::nme::utils::ByteArray_obj::__init__();
::cpp::Lib_obj::__boot();
::cpp::io::_Process::Stdin_obj::__boot();
::cpp::io::_Process::Stdout_obj::__boot();
::cpp::io::Process_obj::__boot();
::cpp::zip::Compress_obj::__boot();
::cpp::FileKind_obj::__boot();
::cpp::FileSystem_obj::__boot();
::cpp::io::FileOutput_obj::__boot();
::cpp::io::FileSeek_obj::__boot();
::cpp::io::File_obj::__boot();
::cpp::zip::Flush_obj::__boot();
::cpp::io::FileInput_obj::__boot();
::haxe::Log_obj::__boot();
::cpp::rtti::FieldNumericIntegerLookup_obj::__boot();
::cpp::zip::Uncompress_obj::__boot();
::cpp::Sys_obj::__boot();
::nme::events::Event_obj::__boot();
::nme::events::MouseEvent_obj::__boot();
::nme::events::TouchEvent_obj::__boot();
::box2D::collision::B2TOIInput_obj::__boot();
::box2D::dynamics::contacts::B2Contact_obj::__boot();
::box2D::dynamics::contacts::B2PolyAndCircleContact_obj::__boot();
::nme::display::StageDisplayState_obj::__boot();
::nme::events::ProgressEvent_obj::__boot();
::box2D::common::math::B2Mat22_obj::__boot();
::box2D::dynamics::B2ContactImpulse_obj::__boot();
::box2D::dynamics::B2Island_obj::__boot();
::box2D::common::math::B2Vec2_obj::__boot();
::box2D::dynamics::contacts::B2PositionSolverManifold_obj::__boot();
::box2D::common::math::B2Transform_obj::__boot();
::box2D::dynamics::B2Body_obj::__boot();
::nme::net::URLLoaderDataFormat_obj::__boot();
::box2D::dynamics::joints::B2JointDef_obj::__boot();
::box2D::dynamics::joints::B2MouseJointDef_obj::__boot();
::List_obj::__boot();
::box2D::dynamics::joints::B2JointEdge_obj::__boot();
::nme::geom::Point_obj::__boot();
::box2D::collision::shapes::B2Shape_obj::__boot();
::box2D::collision::shapes::B2EdgeShape_obj::__boot();
::IntIter_obj::__boot();
::haxe::io::Output_obj::__boot();
::haxe::io::Input_obj::__boot();
::nme::net::URLRequestMethod_obj::__boot();
::Hash_obj::__boot();
::nme::display::GradientType_obj::__boot();
::IntHash_obj::__boot();
::box2D::dynamics::B2ContactFilter_obj::__boot();
::box2D::dynamics::B2FixtureDef_obj::__boot();
::nme::net::URLRequest_obj::__boot();
::box2D::dynamics::controllers::B2ControllerEdge_obj::__boot();
::StringTools_obj::__boot();
::haxe::io::Bytes_obj::__boot();
::box2D::dynamics::contacts::B2ContactEdge_obj::__boot();
::box2D::collision::B2OBB_obj::__boot();
::haxe::io::BytesBuffer_obj::__boot();
::com::firmamentengine::firmament::FRenderer_obj::__boot();
::com::firmamentengine::firmament::FWireframeRenderer_obj::__boot();
::box2D::dynamics::contacts::B2PolygonContact_obj::__boot();
::box2D::common::math::B2Sweep_obj::__boot();
::box2D::common::B2Color_obj::__boot();
::box2D::dynamics::B2TimeStep_obj::__boot();
::box2D::dynamics::B2World_obj::__boot();
::nme::events::IEventDispatcher_obj::__boot();
::nme::events::EventDispatcher_obj::__boot();
::nme::display::IBitmapDrawable_obj::__boot();
::nme::Loader_obj::__boot();
::nme::display::DisplayObject_obj::__boot();
::nme::display::InteractiveObject_obj::__boot();
::nme::display::DisplayObjectContainer_obj::__boot();
::nme::display::Stage_obj::__boot();
::nme::display::TouchInfo_obj::__boot();
::box2D::dynamics::joints::B2PulleyJointDef_obj::__boot();
::nme::display::Graphics_obj::__boot();
::box2D::dynamics::joints::B2RevoluteJointDef_obj::__boot();
::box2D::common::B2Settings_obj::__boot();
::box2D::collision::B2SeparationFunction_obj::__boot();
::box2D::common::math::B2Vec3_obj::__boot();
::box2D::dynamics::joints::B2DistanceJointDef_obj::__boot();
::box2D::collision::ClipVertex_obj::__boot();
::nme::display::StageQuality_obj::__boot();
::box2D::collision::B2RayCastOutput_obj::__boot();
::com::firmamentengine::firmament::FWorld_obj::__boot();
::nme::net::URLVariables_obj::__boot();
::box2D::dynamics::B2FilterData_obj::__boot();
::box2D::collision::B2Manifold_obj::__boot();
::box2D::collision::B2DistanceProxy_obj::__boot();
::box2D::collision::B2Simplex_obj::__boot();
::box2D::collision::B2Distance_obj::__boot();
::nme::geom::Rectangle_obj::__boot();
::box2D::dynamics::joints::B2Joint_obj::__boot();
::box2D::dynamics::joints::B2WeldJoint_obj::__boot();
::box2D::collision::B2ContactPoint_obj::__boot();
::box2D::dynamics::B2ContactManager_obj::__boot();
::nme::display::BlendMode_obj::__boot();
::ValueType_obj::__boot();
::Type_obj::__boot();
::nme::errors::Error_obj::__boot();
::box2D::common::math::B2Math_obj::__boot();
::com::firmamentengine::firmament::FWorldPositional_obj::__boot();
::nme::events::TextEvent_obj::__boot();
::nme::events::ErrorEvent_obj::__boot();
::nme::events::IOErrorEvent_obj::__boot();
::box2D::collision::B2SimplexCache_obj::__boot();
::box2D::dynamics::joints::B2RevoluteJoint_obj::__boot();
::box2D::dynamics::joints::B2FrictionJointDef_obj::__boot();
::nme::display::JointStyle_obj::__boot();
::Reflect_obj::__boot();
::box2D::dynamics::contacts::B2CircleContact_obj::__boot();
::box2D::dynamics::joints::B2PulleyJoint_obj::__boot();
::box2D::dynamics::joints::B2MouseJoint_obj::__boot();
::box2D::collision::B2ManifoldPoint_obj::__boot();
::box2D::dynamics::joints::B2GearJointDef_obj::__boot();
::com::firmamentengine::firmament::FPhysicsWorld_obj::__boot();
::box2D::dynamics::joints::B2LineJointDef_obj::__boot();
::nme::display::Sprite_obj::__boot();
::com::firmamentengine::firmament::FWorldPositionalInterface_obj::__boot();
::com::firmamentengine::firmament::FCamera_obj::__boot();
::nme::display::IGraphicsData_obj::__boot();
::box2D::collision::B2Collision_obj::__boot();
::box2D::dynamics::contacts::B2ContactConstraintPoint_obj::__boot();
::nme::Lib_obj::__boot();
::box2D::dynamics::B2ContactListener_obj::__boot();
::nme::utils::Timer_obj::__boot();
::box2D::dynamics::joints::B2DistanceJoint_obj::__boot();
::Date_obj::__boot();
::box2D::collision::shapes::B2MassData_obj::__boot();
::nme::events::JoystickEvent_obj::__boot();
::nme::utils::IDataInput_obj::__boot();
::haxe::io::Eof_obj::__boot();
::nme::geom::ColorTransform_obj::__boot();
::box2D::dynamics::joints::B2GearJoint_obj::__boot();
::box2D::collision::IBroadPhase_obj::__boot();
::box2D::collision::B2DynamicTreeBroadPhase_obj::__boot();
::box2D::dynamics::joints::B2PrismaticJointDef_obj::__boot();
::box2D::dynamics::contacts::B2ContactFactory_obj::__boot();
::com::firmamentengine::firmament::Main_obj::__boot();
::nme::display::ManagedStage_obj::__boot();
::nme::display::StageAlign_obj::__boot();
::box2D::collision::B2DistanceOutput_obj::__boot();
::box2D::collision::Features_obj::__boot();
::nme::display::Tilesheet_obj::__boot();
::StringBuf_obj::__boot();
::box2D::collision::B2DynamicTreeNode_obj::__boot();
::com::firmamentengine::firmament::FRenderable_obj::__boot();
::com::firmamentengine::firmament::FEntity_obj::__boot();
::com::firmamentengine::firmament::FPhysicsEntity_obj::__boot();
::box2D::collision::B2DynamicTreePair_obj::__boot();
::box2D::dynamics::B2Fixture_obj::__boot();
::box2D::dynamics::B2BodyDef_obj::__boot();
::box2D::collision::B2DistanceInput_obj::__boot();
::box2D::collision::B2TimeOfImpact_obj::__boot();
::nme::display::SpreadMethod_obj::__boot();
::nme::net::URLLoader_obj::__boot();
::nme::events::TimerEvent_obj::__boot();
::box2D::collision::B2RayCastInput_obj::__boot();
::nme::events::KeyboardEvent_obj::__boot();
::nme::utils::Endian_obj::__boot();
::box2D::dynamics::contacts::B2EdgeAndCircleContact_obj::__boot();
::box2D::dynamics::contacts::B2ContactConstraint_obj::__boot();
::box2D::dynamics::controllers::B2Controller_obj::__boot();
::ApplicationMain_obj::__boot();
::nme::display::Bitmap_obj::__boot();
::nme::display::StageScaleMode_obj::__boot();
::box2D::collision::B2WorldManifold_obj::__boot();
::box2D::dynamics::contacts::B2ContactSolver_obj::__boot();
::nme::geom::Matrix_obj::__boot();
::nme::utils::WeakRef_obj::__boot();
::nme::display::TriangleCulling_obj::__boot();
::nme::display::LineScaleMode_obj::__boot();
::nme::display::MovieClip_obj::__boot();
::nme::media::SoundTransform_obj::__boot();
::Std_obj::__boot();
::box2D::collision::B2AABB_obj::__boot();
::haxe::Timer_obj::__boot();
::nme::filters::BitmapFilter_obj::__boot();
::box2D::collision::B2DynamicTree_obj::__boot();
::nme::events::EventPhase_obj::__boot();
::nme::errors::RangeError_obj::__boot();
::box2D::dynamics::joints::B2Jacobian_obj::__boot();
::box2D::dynamics::contacts::B2ContactRegister_obj::__boot();
::box2D::dynamics::joints::B2WeldJointDef_obj::__boot();
::box2D::dynamics::B2DestructionListener_obj::__boot();
::box2D::collision::shapes::B2CircleShape_obj::__boot();
::nme::media::SoundChannel_obj::__boot();
::haxe::io::Error_obj::__boot();
::nme::events::FocusEvent_obj::__boot();
::nme::display::PixelSnapping_obj::__boot();
::box2D::collision::B2SimplexVertex_obj::__boot();
::box2D::dynamics::joints::B2FrictionJoint_obj::__boot();
::nme::utils::ByteArray_obj::__boot();
::box2D::collision::shapes::B2PolygonShape_obj::__boot();
::nme::display::InterpolationMethod_obj::__boot();
::com::firmamentengine::firmament::FVector_obj::__boot();
::box2D::dynamics::joints::B2PrismaticJoint_obj::__boot();
::nme::errors::EOFError_obj::__boot();
::box2D::dynamics::contacts::B2PolyAndEdgeContact_obj::__boot();
::box2D::dynamics::B2DebugDraw_obj::__boot();
::box2D::dynamics::joints::B2LineJoint_obj::__boot();
::nme::geom::Transform_obj::__boot();
::nme::display::CapsStyle_obj::__boot();
::box2D::common::math::B2Mat33_obj::__boot();
::com::firmamentengine::firmament::FGame_obj::__boot();
::nme::events::Listener_obj::__boot();
::box2D::collision::B2ContactID_obj::__boot();
::nme::display::BitmapData_obj::__boot();
}


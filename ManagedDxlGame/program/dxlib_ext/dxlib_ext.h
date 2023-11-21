#pragma once
#include "../library/tnl_util.h"
#include "../library/tnl_csv.h"
#include "../library/tnl_font_texture.h"
#include "../library/tnl_hierarchy_tree.h"
#include "../library/tnl_input.h"
#include "../library/tnl_intersect.h"
#include "../library/tnl_link_linear.h"
#include "../library/tnl_math.h"
#include "../library/tnl_matrix.h"
#include "../library/tnl_quaternion.h"
#include "../library/tnl_sequence.h"
#include "../library/tnl_shared_factory.h"
#include "../library/tnl_timer_fluct.h"
#include "../library/tnl_vector2i.h"
#include "../library/tnl_vector3.h"
#include "../library/tnl_seek_unit.h"
#include "../library/stb_image.h"
#include "../library/json11.hpp"
#include "DxLib.h"
#include "dxlib_ext_camera.h"
#include "dxlib_ext_mesh.h"
#include "dxlib_ext_texture.h"

const int DXE_WINDOW_WIDTH = 1280;
const int DXE_WINDOW_HEIGHT = 720;
const float DXE_FIX_FPS = 60.0f;

void DrawStringEx(const float x, const float y, const int color, const char* _str, ...);
void DrawStringToHandleEx(const float x, const float y, const int color, const int hdl, const char* _str, ...);
void DrawLineEx(const tnl::Vector3& p, const tnl::Vector3& v, const float length, const int color = -1);
void DrawBoxEx(const tnl::Vector3& p, const float width, const float height, const bool fill = true, const int color = -1);
void DrawRotaBox(const tnl::Vector3& pos, float w, float h, float rad, int color = -1);

void DrawFpsIndicator(const tnl::Vector3& pos, float delta_time);


// �f�o�b�O�p�̃O���b�h�n��
// arg1... �J����
// arg2... �O���b�h�}�X�̃T�C�Y
// arg3... �O���b�h����ׂ�� ( �����Ŏw�� )
// arg4... 16�i���J���[
// tips... ���̊֐����g�p����O�ɃJ�����𐶐����� update �֐������s���Ă�������
void DrawGridGround( const dxe::Camera* camera, const float square_size, int row_num, int color = 0x99999999 );


void DrawAxis( const dxe::Camera* camera, const tnl::Vector3& pos, const tnl::Quaternion& rot, const float length);
void DrawOBB( const dxe::Camera* camera, const tnl::Vector3& pos, const tnl::Quaternion& rot, const tnl::Vector3& size, const int color = 0x00ff00ff );
void DrawAABB( const dxe::Camera* camera, const tnl::Vector3& pos, const tnl::Vector3& size, const int color = 0x0000ffff);
void DrawBdSphere( const dxe::Camera* camera, const tnl::Vector3& pos, const float radius);


std::string GetDragFilePathReadTrigger();

/***************************************************************************************** 
//
//3D start up sample
//

#include <time.h>
#include <string>
#include <numbers>
#include <functional>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"

dxe::Camera* camera = nullptr;
dxe::Mesh* mesh = nullptr;
Shared<dxe::Texture> texture = nullptr;

//------------------------------------------------------------------------------------------------------------
// �Q�[���N�����ɂP�x�������s����܂�
void gameStart(){
	srand(time(0));

	SetFogEnable(true);
	SetFogColor(32, 32, 32);
	SetFogStartEnd(500.0f, 1500.0f);
	ChangeLightTypeDir( VGet(0.1f, 1.0f, 0.0f) );
	SetBackgroundColor( 32, 32, 32 );

	camera = new dxe::Camera(DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT);

	texture = dxe::Texture::CreateFromFile("graphics/box.bmp");

	mesh = dxe::Mesh::CreateBox(50);
	mesh->setTexture(texture);
	mesh->pos_ = { 0, 0, 1000 };
}

//------------------------------------------------------------------------------------------------------------
// ���t���[�����s����܂�
void gameMain(float delta_time) {

	mesh->rot_ *= tnl::Quaternion::RotationAxis({ 0, 1, 0 }, tnl::ToRadian(1));

	mesh->pos_.z -= 1.0f;

	camera->update();
	mesh->render(camera);

	DrawGridGround(camera, 50, 20);
	DrawFpsIndicator({ 10, DXE_WINDOW_HEIGHT - 10, 0 }, delta_time);
}

//------------------------------------------------------------------------------------------------------------
// �Q�[���I�����ɂP�x�������s����܂�
void gameEnd() {

}

*****************************************************************************************/

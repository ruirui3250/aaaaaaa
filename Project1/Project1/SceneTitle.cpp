//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SWCURE_SCL(o)
#define _HAS_ITERATOR_DEBUGGING(o)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
//#include "SceneMain.h"
#include "GameHead.h"

//�R���g���N�^
CSceneTitle::CSceneTitle()
{

}

//�f�X�g���N�^
CSceneTitle::~CSceneTitle()
{

}

//�Q�[�����C�����������\�b�h
void CSceneTitle::InitScene()
{
	Font::SetStrTex(L"�o�C���X�N���b�V��");
	Font::SetStrTex(L"�G���^�[�L�[�ŃQ�[�����n�߂�");

	//�N���A�I�u�W�F�N�g�o�^
	CObjTitle* obj = new CObjTitle();//�N���A�I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_TITLE, 10);//�N���A�I�u�W�F�N�g�o�^
}

//�Q�[�����C�����s�����\�b�h
void CSceneTitle::Scene()
{

}
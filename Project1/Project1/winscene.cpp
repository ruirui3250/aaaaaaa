//STL�f�o�b�O�@�\���I�t�ɂ���B
#define _SECURE_SCL(o)
#define _HAS_ITERATOR_DEBUGGING(o)

//GameL�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include"GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "winscene.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneWin::CSceneWin()
{

}

//�f�X�g���N�^
CSceneWin::~CSceneWin()
{

}

//���������\�b�h
//�����̓o�^
void CSceneWin::InitScene()
{
	//�O���O���t�B�b�N�ǂݍ��ݓo�^0��
	Draw::LoadImage(L"kekkan.png", 0, TEX_SIZE_512);
	//�O���O���t�B�b�N�ǂݍ���1��
	Draw::LoadImage(L"virusclear.png", 1, TEX_SIZE_512);

	Font::SetStrTex(L"You Win!");
	Font::SetStrTex(L"�G���^�[�L�[�Ń^�C�g���ɖ߂�B");

	//�N���A�I�u�W�F�N�g�o�^
	CObjWin* obj = new CObjWin();//�N���A�I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_WIN, 10);//�N���A�I�u�W�F�N�g�o�^


		//�N���A���w�i�I�u�W�F�N�g�쐬
	CObjClearback* back = new CObjClearback();
	Objs::InsertObj(back, OBJ_CLEAR_BACK, 0);

	//�N���A�E�C���X�쐬
	CObjClearvirus* obj2 = new CObjClearvirus();//�N���A�쐬
	Objs::InsertObj(obj2, OBJ_CLEAR_VIRUS, 1);//�N���A�E�C���X�o�^

}

//���s���\�b�h
void CSceneWin::Scene()
{

}
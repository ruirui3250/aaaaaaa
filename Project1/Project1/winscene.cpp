//STL�f�o�b�O�@�\���I�t�ɂ���B
#define _SECURE_SCL(o)
#define _HAS_ITERATOR_DEBUGGING(o)

//GameL�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

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
	Font::SetStrTex(L"You Win!");
	Font::SetStrTex(L"�G���^�[�L�[�Ń^�C�g���ɖ߂�B");

}

//���s���\�b�h
void CSceneWin::Scene()
{

}
//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SEURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)
//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
//�g�p�w�b�_�[
#include "SceneGameOver.h"
#include "ObjGameOver.h"
#include "GameHead.h"
//�R���X�g���N�^
CSceneGameOver::CSceneGameOver()
{

}
//�f�X�g���N�^
CSceneGameOver::~CSceneGameOver()
{

}
//���������\�b�h
void CSceneGameOver::InitScene()
{
	//	�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);
}
//�Q�[�����C�����s�����\�b�h
void CSceneGameOver::Scene()
{

}
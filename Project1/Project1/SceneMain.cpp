//STL�f�o�b�O�@�\��OFF�ɂ���B
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include"GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneMain.h"
#include"GameHead.h"
//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}
//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//�Q�[�����C�����������\�b�h
void CSceneMain::InitScene()
{
	//�O���O���t�B�b�N�ǂݍ���0��  �w�i
	Draw::LoadImage(L"SceneMain.png",5,TEX_SIZE_512);

	Draw::LoadImage(L"image.png", 1, TEX_SIZE_512);

	Draw::LoadImage(L"��l���@.png", 0, TEX_SIZE_512);
	//�O���O���t�B�b�N�t�@�C����ǂݍ���1�Ԃɓo�^ �{�X�O���t�B�b�N��o�^
	//Draw::LoadImage(L"BossBack.png",,TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjHero*obj=new CObjHero();//��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj,OBJ_HERO,0);//��l���I�u�W�F�N�g�}�l�[�W���[��o�^

		//�N���A���w�i�I�u�W�F�N�g�쐬
	CObjSceneMain* back = new CObjSceneMain();
	Objs::InsertObj(back, OBJ_SCENE_MAIN, 5);

	//�^�C��������
	m_time = 0;

}

//�Q�[���V�[�����s�����\�b�h
void CSceneMain::Scene()
{
	m_time++;

	if (m_time == 30)
	{
		CObjEnemy* obj = new CObjEnemy(799.0f, 400);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	else if (m_time == 80)
	{
		CObjEnemy* obj = new CObjEnemy(799.0f, 300);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
    }
	else if (m_time == 120)
	{
		CObjEnemy* obj = new CObjEnemy(799.0f, 200);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	 else if (m_time == 200)
	{
		CObjEnemy* obj;
		obj = new CObjEnemy(799.0f, 100);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
		obj = new CObjEnemy(799.0f, 500);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	else if (m_time == 400)
	{
		CObjEnemy* obj1;
		obj1 = new CObjEnemy(799.0f, 300);
		Objs::InsertObj(obj1, OBJ_ENEMY, 50);

		CObjAttackEnemy* obj2;
		obj2 = new CObjAttackEnemy(799, 400);
		Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY, 50);

	}
	else if (m_time == 550)
	{
		CObjEnemy* obj1;
		obj1 = new CObjEnemy(799.0f, 400);
		Objs::InsertObj(obj1, OBJ_ENEMY, 50);

		CObjAttackEnemy* obj2;
		obj2 = new CObjAttackEnemy(799, 300);
		Objs::InsertObj(obj2, OBJ_ATTACK_ENEMY, 50);

	}
	else if (m_time == 680)
	{
		CObjEnemy* obj;	
		obj = new CObjEnemy(799.0f, 300);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
		obj = new CObjEnemy(799.0f, 350);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
		obj = new CObjEnemy(799.0f, 250);
		Objs::InsertObj(obj, OBJ_ENEMY, 50);
	}
	else if (m_time == 750)
	{
		CObjAttackEnemy* obj;  
		obj = new CObjAttackEnemy(799, 300);
		Objs::InsertObj(obj, OBJ_ATTACK_ENEMY, 50);
	}
	//else if (m_time == 1000)
	//{
	//	CObjSinEnemy* obj;
	//	for (int i = 0; i < 15; i++)
	//	{
	//		obj = new CObjSinEnemy(799, i * 32);
	//		Objs::InsertObj(obj, OBJ_SIN_ENEMY, 50);
	//	}
	//}
	//else if (m_time == 1100)
	//{
	//	CObjSinEnemy* obj;
	//	for (int i = 0; i < 15; i++)
	//	{
	//		obj = new CObjSinEnemy(799, i * 32 + 64);
	//		Objs::InsertObj(obj, OBJ_SIN_ENEMY, 50);
	//	}
	//}
	//else if (m_time == 1200)
	//{
	//	CObjSinEnemy* obj;
	//	for (int i = 0; i < 15; i++)
	//	{
	//		obj = new CObjSinEnemy(799, i * 32);
	//		Objs::InsertObj(obj, OBJ_SIN_ENEMY, 50);
	//	}
	//}
	//else if (m_time == 1300)
	//{
	//	CObjSinEnemy* obj;
	//	for (int i = 0; i < 15; i++)
	//	{
	//		obj = new CObjSinEnemy(799, i * 32);
	//		Objs::InsertObj(obj, OBJ_SIN_ENEMY, 50);
	//	}
//
//		CObjDiffusionEnemy* obj2;
//		obj2 = new CObjDiffusionEnemy(799, 300);
//		Objs::InsertObj(obj2, OBJ_DIFFUSION_ENEMY, 50);
	//}
//	else if (m_time == 1500)
//	{
//		CObjHomingEnemy* obj;
//		obj = new CObjHomingEnemy(799, 500);
//		Objs::InsertObj(obj, OBJ_HOMING_ENEMY, 50);
//	}
	//else if (m_time == 2000)
	//{
		//���y�`�F���W
		//Audio::Stop(0);//0�ȃX�g�b�v
		//Audio::Start(1);//1�ȖڃX�^�[�g

		//CObjBoss* obj;
		//obj = new CObjBoss(300, 100);
		//Objs::InsertObj(obj, OBJ_BOSS_ENEMY, 50);
	//}
}
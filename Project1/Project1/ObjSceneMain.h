#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//object�w�i
class CObjSceneMain :public CObj
{
public:
	CObjSceneMain() {};
	~CObjSceneMain() {};

	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:

	float m_x1;//�w�i�P�̈ʒu���
	float m_x2;//�w�i2�̈ʒu���
};

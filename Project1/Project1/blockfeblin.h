#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�u���b�N���w�i
class CObjBlockfeblin :public CObj
{
public:
	CObjBlockfeblin() {};
	~CObjBlockfeblin() {};
	void Init();
	void Action();
	void Draw();//�h���[
private:
	//�}�b�v���
	int m_map[10][10];
};

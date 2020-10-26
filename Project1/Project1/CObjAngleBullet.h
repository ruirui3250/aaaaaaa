#pragma once
//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G�@�p�x�e��
class CObjAngleBullet : public CObj
{
public:
	CObjAngleBullet(float x, float y, float r, float speed);//�R���X�g���N�^�ʒu�������炤
	~CObjAngleBullet() {};
	void Init();  //�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	float m_x; //�G�@��x�����̈ʒu
	float m_y; //�G�@��y�����̈ʒu
	float m_vx; //�G�@�ړ��x�N�g��X
	float m_vy; //�G�@�ړ��x�N�g��Y
	float m_r;  //�ړ�����p�x
	float m_speed; //���x

	int  m_ani;
	int  m_ani_time;
	bool m_del;
	RECT_F m_eff;
};
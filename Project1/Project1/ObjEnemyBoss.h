#pragma once
//�g�p����w�b�_�[
#include "GameL/\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G�@
class CObjBoss :public CObj
{
public:
	CObjBoss(float x, float y);//�R���X�g���N�^�ʒu�������炤
	~CObjBoss() {};
	void Init();      //�C�j�V�����C�Y
	void Action();    //�A�N�V����
	void Draw();      //�h���[
private:
	float m_x;  //�G�@�̂������̈ʒu
	float m_y;  //�G�@�̂������̈ʒu
	float m_vx; //�G�@�ړ��x�N�g����
	float m_vy; //�G�@�ړ��x�N�g����
	float m_r;  //�T�C���J�[�u�p�p�x
	int   m_time;//�e�ۊԊu�p
	int   m_hp; //�{�X�̃q�b�g�|�C���g
};
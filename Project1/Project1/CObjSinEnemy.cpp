//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"CObjSinEnemy.h"
#include"UtilityModule.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjSinEnemy::CObjSinEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjSinEnemy::Init()
{
	m_r = 0.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;
	//�����蔻��hitbox���쐬�B
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_SIN_ENEMY, 1);
}
//�A�N�V����
void CObjSinEnemy::Action()
{
	//�p�x�v�Z
	m_r += 2.0f;
	//360���ŏ����l�ɖ߂�
	if (m_r > 360.0f)
		m_r = 0.0f;
	//�ړ�����
	m_vx = -1.0f;
	m_vy = sin(3.14 / 180 * m_r);//sin�V�[�^�����߂�m_vy�ɓ����B


	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//���x������
	m_vx *= 1.5f;
	m_vy *= 1.5f;

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);
	//�ړ��x�N�g�������W�ɉ��Z
	m_x += m_vx;
	m_y += m_vy;
	//HITBOX�̓��e�X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
	//Sin�@�����S�ɗ̈�O�ɏo����I�u�W�F�N�g��j�󂷂�B
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);//���g�ɍ폜����
		Hits::DeleteHitBox(this);//�V���G�@�����L����hitbox���폜
		return;
	}
	//�e�ۂɐڐG���Ă��邩�ǂ������ׂ�.
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//�h���[
void CObjSinEnemy::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`��؂���ʒu
	RECT_F dst;//�`���\��

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 32.0f;
	src.m_right = 64.0f;
	src.m_bottom = 32.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 32.0f + m_x;
	dst.m_right = 0.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//0�Ԗڂɓo�^�����O���t�B�b�N��`��B
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
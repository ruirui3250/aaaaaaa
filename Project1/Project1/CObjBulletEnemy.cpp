//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "CObjBullteEnemy.h"
#include"UtilityModule.h"

//�g�p����l�[��
using namespace GameL;

CObjBulletEnemy::CObjBulletEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjBulletEnemy::Init()
{
	m_eff.m_top = 32;
	m_eff.m_left = 0;
	m_eff.m_right = 32;
	m_eff.m_bottom = 64;
	m_ani = 0;
	m_ani_time = 0;

	m_vx = -1.0f;
	m_vy = 0.0f;

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//�����蔻��pHitBox���쐬�B
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_BULLET_ENEMY, 1);

}

//�A�N�V����
void CObjBulletEnemy::Action()
{
	//Resources�̕`�敨RECT
	m_eff = GetBulletEffec(&m_ani, &m_ani_time, m_del, 2);

	//�e�ۏ��ŏ���
	if (m_del == true)
	{
		//���e�A�j���[�V�����I���Ŗ{���ɃI�u�W�F�N�g�̔j���B
		if (m_ani == 4)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
		return; //���ŏ����́A�����ŃA�N�V�������\�b�h���I�������B
	}
	//�e�ێ��s����
	//�ړ�
	m_x += m_vx * 5.0f;
	m_y += m_vy * 5.0f;

	//�G�@�e�ۂ̌�M�p�|�C���^�[���l���B
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);	//HitBox�̈ʒu��G�@�e�ۂ̈ʒu���X�V�B
	//�̈�O�ɏo����e�ۂ�j���B
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false); //���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this);//�G�@�e�ۂ����L����HitBox���폜
		return;
	}
	//��l���@object�ƐڐG������G�@�e�ۍ폜�B
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		m_del = true; //���Ŏ��s
		hit->SetInvincibility(true);//�����蔻�薳��
	}
}

//�h���[
void CObjBulletEnemy::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F dst;//�`���\��

	//�؂���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//0�Ԗڂɓo�^�����O���t�B�b�N��`��B
	Draw::Draw(0, &m_eff, &dst, c, 180.0f);
}
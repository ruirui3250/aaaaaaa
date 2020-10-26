//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemyBoss.h"
#include "UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBoss::CObjBoss(float x, float y)
{
	m_x = x;
	m_y = y;
}
//�C�j�V�����C�Y
void CObjBoss::Init()
{
	m_hp = 30;
	m_time = 0;
	m_r = 0.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x + 100, m_y + 50, 250, 200, ELEMENT_ENEMY, OBJ_BOSS_ENEMY, 1);
}

//�A�N�V����
void CObjBoss::Action()
{
	m_time++;

	//�ʏ�e����
	if (m_time % 50 == 0)
	{
		//�e�ۓG�@�I�u�W�F�N�g
		CObjBulletEnemy* obj_b = new CObjBulletEnemy(m_x + 100, m_y + 50);
		Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY, 100);
	}



	//m_time�̏�����
	if (m_time > 1000)
	{
		m_time = 0;
	}




	//�p�x���Z
	m_r += 2.0f;

	//360���ŏ����l�ɖ߂�
	if (m_r > 360.0f)
		m_r = 0.0f;

	//�ړ�����
	m_vx = 0.0f;
	m_vy = sin(3.14 / 180 * m_r);

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//�x�N�g���̒��������߂�(�O�����̒藝)
	float r = 0.0f;
	r = m_vx * m_vx + m_vy * m_vy;
	r = sqrt(r);//r�����[�g�����߂�

	//������0���ǂ������ׂ�
	if (r == 0.0f)
	{
		;//0�Ȃ牽�����Ȃ�
	}
	else
	{
		//���K�����s���B
		m_vx = 1.0f / r * m_vx;
		m_vy = 1.0f / r * m_vy;
	}

	//���x�t����B
	m_vx *= 1.5f;
	m_vy *= 1.5f;

	//�ړ��x�N�g�������W�ɉ��Z����
	m_x += m_vx;
	m_y += m_vy;

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + 100, m_y + 50);

	//�G�@�����S�ɗ̈�O�ɏo����G�@��j������
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false); //���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this); //�G�@�����L����HitBox�ɍ폜����
	}
	//�e�ۂƐڐG���Ă�����HP�����炷
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
	}

	//HP��0�ɂȂ�����j��
	if (m_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);


	}
}

//�h���[
void CObjBoss::Draw()
{
	//�`��J���[���@R=RED  G=Green B=Blue A=alpha(���ߏ��)
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 260.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 512.0f + m_x;
	dst.m_bottom = 260.0f + m_y;

	//1�Ԗڂɓo�^�����O���t�B�b�N��src.dst.c�̏������ɕ`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

}



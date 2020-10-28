//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include "GameHead.h"
#include"ObjBullet.h"
#include"UtilityModule.h"
//#include"GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBullet::CObjBullet(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjBullet::Init()
{
	m_eff.m_top = 32;
	m_eff.m_left = 0;
	m_eff.m_right = 32;
	m_eff.m_bottom = 64;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;
	m_vx = 0.0f;

	//�����蔻��HItBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_BULLET, 1);
}
//�A�N�V����
void CObjBullet::Action()
{
	//Resources�̕`�敨RECT
	m_eff = GetBulletEffect(&m_ani, &m_ani_time, m_del, 2);

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
	m_vx += 1.0f;
	m_x += m_vx;

	//�e�ۂ�HitBox�X�V�p�|�C���^�[�擾
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);//HitBox�̈ʒu��e�ۂ̈ʒu���X�V

	//�̈�O�ɏo����e�۔j��
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false); //���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this);//�G�@�e�ۂ����L����HitBox���폜
		return;
	}

	////�G�@�I�u�W�F�N�g�ɂԂ�������e�ۍ폜�B
	//if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	//{
	//	this->SetStatus(false); //���g�ɍ폜����
	//	Hits::DeleteHitBox(this);//�e�ۂ����L����HITBOX�폜
	//}

	//�����蔻����s���I�u�W�F�N�g���
	int data_base[4] =
	{
		OBJ_ENEMY,
		OBJ_ATTACK_ENEMY,
		/*OBJ_DIFFUSION_ENEMY,
		OBJ_HOMING_ENEMY,*/
		OBJ_BOSS_ENEMY,
	};

	//�I�u�W�F�N�g��񕔂ɓ����蔻����s���B������΍폜�B
	for (int i = 0; i < 4; i++)
	{
		if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		{
			/*Audio::Start(3);*/
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}

}
//�h���[
void CObjBullet::Draw()
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
	Draw::Draw(1, &m_eff, &dst, c, 0.0f);
}
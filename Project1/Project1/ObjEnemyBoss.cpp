//�g�p����w�b�_�[�t�@�C��
#include "GameL/\DrawTexture.h"
#include "GameL/\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemyBoss.h"
#include "UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�^���X�^
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
        CObjBulletEnemy* obj_b = new CObjBulletEnemy(m_x + 68, m_y + 114);//�e�ۓG�@�I�u�W�F�N�g�쐬
        Objs::InsertObj(obj_b, OBJ_BULLET_ENEMY, 100);//�e�ۓG�@�I�u�W�F�N�g�o�^
    }
    //360�x�e�۔���
    if (m_time % 200 == 0)
    {
    //    //19����������
    //    CObjAngleBullet* obj_b;
    //    for (int i = 0; i < 360; i += 20)
    //    {
    //        //�p�xi�Ŋp�x�e�۔���
    //        obj_b = new CObjAngleBullet(m_x + 124, m_y + 91, i, 5.0f);
    //        Objs::InsertObj(obj_b, OBJ_ANGLE_BULLET, 100);
    //    }
    //}
    ////�U���e����
    //if (m_time % 500 == 0)
    //{
    //    //�U���e�ۃI�u�W�F�N�g�쐬
    //    CObjHomingBullet* obj_homing_bullet = new CObjHomingBullet(m_x + 402, m_y + 150);
    //    Objs::InsertObj(obj_homing_bullet, OBJ_HOMING_BULLET, 100);
    }
    //m_time�̏�����
    if (m_time > 1000)
    {
        m_time = 0;
    }


    //�p�x���Z
    m_r += 2.0f;

    //360�ŏ����l�ɖ߂�
    if (m_r > 360.0f)
        m_r = 0.0f;

    //�ړ�����
    m_vx = 0.0f;
    m_vy = sin(3.14 / 180 * m_r);

    //�ړ��x�N�g���̐��K��
    UnitVec(&m_vy, &m_vx);

    //�ړ��x�N�g�������W�ɉ��Z����
    m_x += m_vx;
    m_y += m_vy;

    //HitBox�̓��e���X�V
    CHitBox* hit = Hits::GetHitBox(this);
    hit->SetPos(m_x + 100, m_y + 50);

    //�̈�O�ɏo����e�ۂ�j�󂷂�
    bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
    if (check == false)
    {
        this->SetStatus(false);
        Hits::DeleteHitBox(this);

        return;
    }

    //�e�ۂƐڐG���Ă��邩�ǂ������ׂ�
    if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
    {
        m_hp -= 1;
    }

    //HP��0�ɂȂ�����j��
    if (m_hp <= 0)
    {
        this->SetStatus(false);
        Hits::DeleteHitBox(this);

        Scene::SetScene(new CSceneWin());
        
    }
}

//�h���[
void CObjBoss::Draw()
{
    //�`��J���[���@R=RED�@G=GREEN�@B=BLUE�@A=ALPHA�i���ߏ��j
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    RECT_F src;//�`�挳�؂���ʒu
    RECT_F dst;//�`���\���ʒu

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

    //1�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������Ƃɕ`��
    Draw::Draw(1, &src, &dst, c, 0.0f);
}
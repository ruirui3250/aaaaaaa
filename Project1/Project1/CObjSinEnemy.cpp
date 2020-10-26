//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "CObjSinEnemy.h"
#include "UtilityModule.h"
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
    //�����蔻��pHitBox���쐬
    Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_SIN_ENEMY, 1);
}
//�h���[
void CObjSinEnemy::Draw()
{
    //�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��)
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    RECT_F src;//�`�挳�؂���ʒu
    RECT_F dst;//�`���\���ʒu

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

    //0�Ԗڂɓo�^�����O���t�B�b�N��src,dst,c�̏������ɕ`��
    Draw::Draw(0, &src, &dst, c, 0.0f);
}
//�A�N�V����
void CObjSinEnemy::Action()
{
    //�p�x���Z
    m_r += 2.0f;

    //360���ŏ������ɖ߂�
    if (m_r > 360.0f)
        m_r = 0.0f;

    //�ړ�����
    m_vx = -1.0f;
    m_vy = sin(3.14 / 180 * m_r);//sin�����߂�m_vy�ɓ����

    //�ړ��x�N�g���̐��K��
    UnitVec(&m_vy, &m_vx);

    //�x�N�g���̒��������߂�(�O�����̒藝)
    float r = 0.0f;
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

    //���x�t����
    m_vx += 1.5f;
    m_vy += 1.5f;

    //�ړ��x�N�g�������W�ɉ��Z
    m_x += m_vx;
    m_y += m_vy;

    //HitBox�̓��e���X�V
    CHitBox* hit = Hits::GetHitBox(this);
    hit->SetPos(m_x, m_y);

    //Sin�G�@�����S�ɗ̈�O�ɏo����G�@��j������
    bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
    if (check == false)
    {
        this->SetStatus(false);//���g�ɍ폜���߂��o��
        Hits::DeleteHitBox(this);//Sin�G�@�����L����HitBox�ɍ폜����
        return;
    }

    //�e�ۂƐڐG���Ă��邩�ǂ������ׂ�
    if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
    {
        this->SetStatus(false);
        Hits::DeleteHitBox(this);
    }
}

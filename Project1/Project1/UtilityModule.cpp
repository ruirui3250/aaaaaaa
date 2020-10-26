//�g�p����w�b�_�[
#include <math.h>   //���w�v�Z�w�b�_�[
#include "GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//---UnitVec�֐�
//����1�@float* vx  :�x�N�g����X�����̃|�C���^
//����2�@float* vy  :�x�N�g����Y�����̃|�C���^
//�߂�l bool     �@:true=�v�Z�����@false=�v�Z���s
//���e
//�����̃x�N�g���𐳋K�������̒l��vx,vy�ɕύX���܂�
#include <math.h>

bool UnitVec(float* vx, float* vy)
{
    //�x�N�g���̒��������߂�(�O�����̒藝)
    float r = 0.0f;
    r = (*vx) * (*vx) + (*vy) * (*vy);
    r = sqrt(r);//�������[�g�����߂�

    //������0���ǂ������ׂ�
    if (r == 0.0f)
    {
        ;//0�Ȃ牽�����Ȃ�
    }
    else
    {
        //���������s��
        (*vx) = 1.0f / r * (*vx);
        (*vy) = 1.0f / r * (*vy);
    }

    return true;
}

//---CheckWindow�֐�
//����1�@float pos_x�@�@�@�@:�̈�O���ǂ������ׂ�X���W
//����2�@float pos_y        :�̈�O���ǂ������ׂ�Y���W
//����3�@float window_x     :�̈��top�̈ʒu
//����4�@float window_y     :�̈��left�̈ʒu
//����5�@float window_w     :�̈��right�̈ʒu
//����6�@float window_h     :�̈��bottom�̈ʒu
//�߂�l�@bool     :true=�̈���@false=�̈�O
//���e
//�̈�����ǂ������ׂ�ʒupos_(x,y)��window_(xywh)�̓����O�����ׂ�
bool CheckWindow(float pos_x, float pos_y,
    float window_x, float window_y, float window_w, float window_h)
{
    if (pos_x < window_x)
    {
        return false;//�̈�O
    }
    if (pos_x > window_w)
    {
        return false;//�̈�O
    }
    if (pos_y < window_y)
    {
        return false;//�̈�O
    }
    if (pos_y > window_h)
    {
        return false;//�̈�O
    }

    return true;//�̈��
}

//---GetAtan2Angle�֐�
//����1   float w�@�@�F��
//����2   float h�@�@�F����
//�߂�l  float�@�@�@�F����(0�`360)
//���e
//�����ƕ����璼�p�O�p�`������Ɖ��肵�Ă��̊p�x�����߂�
float GetAtan2Angle(float w, float h)
{
    //atan2�Ŋp�x�����߂�
    float r = atan2(h, w) * 180.0f / 3.14f;

    //-180�`-0��180�`-360�ɕύX
    if (r < 0)
    {
        r = 360 - fabs(r);
    }

    return r;
}

/*
---GetBulletEffec�֐�
����1�@�@int* ani      ���e�A�j���[�V����
����2�@�@int* ani_time ���e�A�j���[�V�����Ԋu�^�C��
����3�@�@bool del      �폜�`�F�b�N(true=���e�G�t�F�N�g�@false=�ʏ�̒e��)
����4�@�@int  timintg  �Ԋu���
�߂�l�@RECT_F eff;    �`�ʂ���RECT
del�Œe�ۂ�RECT�⒅�e�G�t�F�N�g��RECT(�A�j���[�V������RECT��Ԃ�)
*/
RECT_F GetBulletEffect(int* ani, int* ani_time, bool del, int timing)
{
    //�Ԃ�RECT���
    RECT_F rect;

    //�v���O�Œʏ�e�ۂ����e�A�j���[�V������������
    if (del == true)
    {
        //���e�A�j���[�V����
        //���\�[�X���e�A�j���[�V����
        RECT_F ani_src[4] =
        {
            {32,0,32,64},
            {32,32,64,64},
            {32,64,96,64},
            {32,96,128,64},
        };
        //�A�j���[�V�����̃R�}�Ԋu
        if (*ani_time > timing)
        {
            *ani += 1;        //�A�j���[�V�����̃R�}��1�i�߂�
            *ani_time = 0;
        }
        else
        {
            *ani_time += 1;
        }

        rect = ani_src[*ani];//�A�j���[�V������RECT�z�񂩂�m_ani�Ԗ�RECT����n��

    }
    else
    {
        //�e�ۂ̓A�j���[�V�����Ȃ�
        //���\�[�X�e�ۈʒu
        RECT_F bullet = { 0.0f,96.0f,126.0f,32.0f };
        rect = bullet;
    }

    return rect;
}
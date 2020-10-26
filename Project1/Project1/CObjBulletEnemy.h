#pragma once
//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G�@�e��
class CObjBulletEnemy : public CObj
{
public:
    CObjBulletEnemy(float x, float y);
    ~CObjBulletEnemy() {};
    void Init(); //�C�j�V�����C�Y
    void Action(); //�A�N�V����
    void Draw(); //�h���[
private:
    float m_x; //�I�u�W�F�N�g�̈ʒuX
    float m_y; //�I�u�W�F�N�g�̈ʒuY
    float m_vx; //�I�u�W�F�N�g�̈ړ��p�x�N�g��X
    float m_vy; //�I�u�W�F�N�g�̈ړ��p�x�N�g��Y

    int  m_ani;//���e�A�j���[�V�����p
    int  m_ani_time;//���e�A�j���[�V�����Ԋu�^�C��
    bool m_del;   //�폜�`�F�b�N
    RECT_F m_eff; //���e�G�t�F�N�g�`��p
};
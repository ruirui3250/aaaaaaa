#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�FSin�G�@
class CObjSinEnemy : public CObj
{
public:
    CObjSinEnemy(float x, float y);//�R���X�g���N�^
    ~CObjSinEnemy() {};
    void Init(); //�C�j�V�����C�Y
    void Action(); //�A�N�V����
    void Draw(); //�h���[
private:
    float m_x; //�G�@��X�����̈ʒu
    float m_y; //�G�@��Y�����̈ʒu
    float m_vx; //�G�@�ړ��x�N�g��X
    float m_vy; //�G�@�ړ��x�N�g��Y
    float m_r;//�T�C���J�[�u�p�̊p�x
};
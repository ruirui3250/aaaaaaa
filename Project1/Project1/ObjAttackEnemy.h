#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�U���G�@
class CObjAttackEnemy :public CObj
{
public:
    CObjAttackEnemy(float x, float y);
    ~CObjAttackEnemy() {};
    void Init();  //�C�j�V�����C�Y
    void Action(); //�A�N�V����
    void Draw();  //�h���[
private:
    float m_x; //�U���G�@��x�����̈ʒu
    float m_y; //�U���G�@��y�����̈ʒu
    float m_vx; //�U���G�@�ړ��x�N�g��X
    float m_vy; //�U���G�@�ړ��x�N�g��Y

    int m_time;//�U���G�@�p�e�۔��˃^�C�~���O�p
};
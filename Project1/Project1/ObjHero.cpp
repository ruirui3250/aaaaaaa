//�g�p����w5�b�_�[�t�@�C��INput
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "objhero.h"



//�C�j�V�����C�Y
void CObjHero::Init()
{

}
//�A�N�V����
void CObjHero::Action()
{

}
//�h���[
void CObjHero::Draw()
{
	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f, };
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 32.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 32.0f;
	dst.m_bottom = 32.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
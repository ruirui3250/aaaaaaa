//�g�p����w5�b�_�[�t�@�C��INput
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "Objhero.h"



//�C�j�V�����C�Y
void CObjHero::Init()
{

}
//�A�N�V����
void CObjHero::Action()
{
	//��l���@�̈ړ�
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_x += 3.0f;
	}
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_x -= 3.0f;
	}
	if (Input::GetVKey(VK_UP) == true)

	{
		m_y -= 3.0f;
	}
	if (Input::GetVKey(VK_DOWN) == true)

	{
		m_y += 3.0f;
	}
	//��l�����̈�O�ɍs���Ȃ�����
	if (m_x + 32.0 > 800.0f)
	{
		m_x = 800.0f - 32.0f;//���_�Ɉړ�
	}
	if (m_y + 32.0 > 600.0f)
	{
		m_y = 600.0f - 32.0f;
	}
	if (m_y < 0.0f)
	{
		m_y = 0.0f;
	}
	if (m_x < 0.0f)
	{
		m_x = 0.0f;
	}

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
//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"


#include"GameHead.h"
#include"Objwin.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjWin::Init()
{
	m_key_flag = false;
}
//�A�N�V����
void CObjWin::Action()
{
	//�G���^�[�L�[�������ăV�[���^�C�g�����ڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
	if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjWin::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�t�H���g�̕\��
	Font::StrDraw(L"You Win!", 270, 200, 50, c);
	Font::StrDraw(L"�G���^�[�L�[�Ń^�C�g���߂�B", 170, 500, 30, c);
}
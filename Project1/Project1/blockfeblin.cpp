//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include"GameHead.h"
#include"blockfeblin.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBlockfeblin::Init()
{
	int blockfeblin_data[10][10] =
	{
		{0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,1,1,1,0,0,0},
	};
	//�}�b�v�f�[�^�R�s�[
	memcpy(m_map, blockfeblin_data, sizeof(int) * (10 * 10));

}
//�A�N�V����
void CObjBlockfeblin::Action()
{

}

//�h���[
void CObjBlockfeblin::Draw()
{

}
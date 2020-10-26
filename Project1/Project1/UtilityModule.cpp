#include <math.h>
#include "GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
//----UnitVec�֐�
//�����P�@float* vx :�x�N�g����X�����̃|�C���^
//����2   float* vy :�x�N�g����Y�����̃|�C���^
//�߂�l�@bool      :true=�v�Z�����@flase=�v�Z���s
//���e
//�����̃x�N�g���𐳋K�������̒l��vx,vy�ɕύX���܂�
bool UnitVec(float* vx, float* vy)
{
	//�x�N�g���̒��������߂�i�O�����̒藝�j
	float  r = 0.0f;
	r = (*vx) * (*vx) + (*vy) * (*vy);
	r = sqrt(r);

	//�������O���ǂ������ׂ�
	if (r == 0.0f)
	{
		//0�Ȃ�v�Z���s
		return false;
	}
	else
	{
		//���K�����s���Avx��vy�̎Q�Ɛ�̒l��ύX
		(*vx) = 1.0f / r * (*vx);
		(*vy) = 1.0f / r * (*vy);
	}

	//�v�Z����
	return true;
}
//----CheckWindow�֐�
//�����P float pos_x  :�̈�O���ǂ������ׂ�x�ʒu
//�����Q float pos_y  :�̈�O���ǂ������ׂ�y�ʒu
//�����R float window_x :�̈��top�ʒu
//�����S float window_y :�̈��left�ʒu
//�����T float window_w :�̈��right�ʒu
//�����U float window_h :�̈��bottom�ʒu
//�߂�l bool       :true=�̈��  flase=�̈�O
//���e
//�̈�����ǂ������ׂ�ʒupos_(x,y)��window_(xywh)�̓����O���𒲂ׂ�
bool CheckWindow(float pos_x, float pos_y, float window_x, float window_y, float window_w, float window_h)
{
	//�̈�`�F�b�N
	if (pos_x < window_x)
	{
		return false;  //�̈�O
	}
	if (pos_x > window_w)
	{
		return false; //�̈�O
	}
	if (pos_y < window_y)
	{
		return false; //�̈�O
	}
	if (pos_y > window_h)
	{
		return false; //�̈�O
	}

	return true;   //�̈��
}
//---GetAtan2Angle�֐�
//����1  float w    :��
//����2  float h    :����
//�߂�l float      :�p�x (0���` 360��)
//���e
//�����ƕ����璼�p�O�p�`������Ɖ��肵���̊p�x�����߂�
float GetAtan2Angle(float w, float h)
{
	//atan2�Ŋp�x�����߂�
	float r = atan2(h, w) * 180.0f / 3.14f;

	//-180���` -0�����@180���` 360���ɕϊ�
	if (r < 0)
	{
		r = 360 - fabsf(r);
	}
	return r;
}
//----GetBulletEffec�֐�
//�����P  int*  ani;
//����2   int*  ani_time;
//����3   bool  del;
//����4   int   timing
//�߂�l�@RECT_F eff;
//del�Œe�ۂ�RECT�⒅�eeffect��RECT��Ԃ�
RECT_F GetBulletEffec(int* ani, int* ani_time, bool del, int timing)
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
			{32,96,126,64},
		};
		//�A�j���[�V�����̃R�}�Ԋu
		if (*ani_time > timing)
		{
			*ani += 1;
			*ani_time = 0;
		}
		else
		{
			*ani_time += 1;
		}

		rect = ani_src[*ani];//�A�j���[�V������RECT�z�񂩂�m_ani����n��
	}
	else
	{
		//�e�ۂ̓A�j���[�V��������
		//���\�[�X�e�ۈʒu
		RECT_F bullet = { 0.0f,96.0f,126.0f,32.0f };
		rect = bullet;
	}

	return rect;

}


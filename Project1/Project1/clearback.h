#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//object�N���A��ʂ̓G�L����
class CObjClearback :public CObj
{
public:
	CObjClearback() {};
	~CObjClearback() {};

	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
};
//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include"GameHead.h"
#include"blockfeblin.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBlockfeblin::Init()
{
	int block_data[10][10] =
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

}
//アクション
void CObjBlockfeblin::Action()
{

}

//ドロー
void CObjBlockfeblin::Draw()
{

}
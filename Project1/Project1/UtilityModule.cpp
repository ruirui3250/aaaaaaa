#include <math.h>
#include "GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;
//----UnitVec関数
//引数１　float* vx :ベクトルのX成分のポインタ
//引数2   float* vy :ベクトルのY成分のポインタ
//戻り値　bool      :true=計算成功　flase=計算失敗
//内容
//引数のベクトルを正規化しその値をvx,vyに変更します
bool UnitVec(float* vx, float* vy)
{
	//ベクトルの長さを求める（三平方の定理）
	float  r = 0.0f;
	r = (*vx) * (*vx) + (*vy) * (*vy);
	r = sqrt(r);

	//長さが０かどうか調べる
	if (r == 0.0f)
	{
		//0なら計算失敗
		return false;
	}
	else
	{
		//正規化を行い、vxとvyの参照先の値を変更
		(*vx) = 1.0f / r * (*vx);
		(*vy) = 1.0f / r * (*vy);
	}

	//計算成功
	return true;
}
//----CheckWindow関数
//引数１ float pos_x  :領域外かどうか調べるx位置
//引数２ float pos_y  :領域外かどうか調べるy位置
//引数３ float window_x :領域のtop位置
//引数４ float window_y :領域のleft位置
//引数５ float window_w :領域のright位置
//引数６ float window_h :領域のbottom位置
//戻り値 bool       :true=領域内  flase=領域外
//内容
//領域内かどうか調べる位置pos_(x,y)がwindow_(xywh)の内か外かを調べる
bool CheckWindow(float pos_x, float pos_y, float window_x, float window_y, float window_w, float window_h)
{
	//領域チェック
	if (pos_x < window_x)
	{
		return false;  //領域外
	}
	if (pos_x > window_w)
	{
		return false; //領域外
	}
	if (pos_y < window_y)
	{
		return false; //領域外
	}
	if (pos_y > window_h)
	{
		return false; //領域外
	}

	return true;   //領域内
}
//---GetAtan2Angle関数
//引数1  float w    :幅
//引数2  float h    :高さ
//戻り値 float      :角度 (0°〜 360°)
//内容
//高さと幅から直角三角形があると仮定しその角度を求める
float GetAtan2Angle(float w, float h)
{
	//atan2で角度を求める
	float r = atan2(h, w) * 180.0f / 3.14f;

	//-180°〜 -0°を　180°〜 360°に変換
	if (r < 0)
	{
		r = 360 - fabsf(r);
	}
	return r;
}
//----GetBulletEffec関数
//引数１  int*  ani;
//引数2   int*  ani_time;
//引数3   bool  del;
//引数4   int   timing
//戻り値　RECT_F eff;
//delで弾丸のRECTや着弾effectのRECTを返す
RECT_F GetBulletEffec(int* ani, int* ani_time, bool del, int timing)
{
	//返すRECT情報
	RECT_F rect;

	//プラグで通常弾丸か着弾アニメーション処理分岐
	if (del == true)
	{
		//着弾アニメーション
		//リソース着弾アニメーション
		RECT_F ani_src[4] =
		{
			{32,0,32,64},
			{32,32,64,64},
			{32,64,96,64},
			{32,96,126,64},
		};
		//アニメーションのコマ間隔
		if (*ani_time > timing)
		{
			*ani += 1;
			*ani_time = 0;
		}
		else
		{
			*ani_time += 1;
		}

		rect = ani_src[*ani];//アニメーションのRECT配列からm_ani情報を渡す
	}
	else
	{
		//弾丸はアニメーション無し
		//リソース弾丸位置
		RECT_F bullet = { 0.0f,96.0f,126.0f,32.0f };
		rect = bullet;
	}

	return rect;

}


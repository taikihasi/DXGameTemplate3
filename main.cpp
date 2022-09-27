#include "DxLib.h"

#include "game.h"

// プログラムは WinMain から始まります
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	// windouwモード設定
	ChangeWindowMode(Game::kWindowMode);
	// ウインド名設定
	SetMainWindowText(Game::kTitleText);
	// 画面サイズの設定
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);
	
	if( DxLib_Init() == -1 )		// ＤＸライブラリ初期化処理
	{
		return -1 ;			// エラーが起きたら直ちに終了
	}

	// ダブルバッファモード
	SetDrawScreen(DX_SCREEN_BACK);
	
	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();
		// 画面のクリア
		ClearDrawScreen();
		
		DrawString(0, 0, "gitのテスト してみた\n", GetColor(255,255,255));
		DrawString(0, 0, "gitのテスト 変更\n", GetColor(255, 255, 255));


		// 裏画面を表画面を入れ替える
		ScreenFlip();
		
		// escキーを押したら終了する
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;
		
		// fpsを60に固定
		while (GetNowHiPerformanceCount() - time < 16667)
		{

		}
	
	}
	
		DxLib_End();		// DXライブラリ使用の終了処理

					

		return 0;	// ソフトの終了
	}
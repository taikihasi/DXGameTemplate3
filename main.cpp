#include "DxLib.h"

#include "game.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	// windouw���[�h�ݒ�
	ChangeWindowMode(Game::kWindowMode);
	// �E�C���h���ݒ�
	SetMainWindowText(Game::kTitleText);
	// ��ʃT�C�Y�̐ݒ�
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);
	
	if( DxLib_Init() == -1 )		// �c�w���C�u��������������
	{
		return -1 ;			// �G���[���N�����璼���ɏI��
	}

	// �_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);
	
	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();
		// ��ʂ̃N���A
		ClearDrawScreen();
		
		DrawString(0, 0, "git�̃e�X�g ���Ă݂�\n", GetColor(255,255,255));

		// ����ʂ�\��ʂ����ւ���
		ScreenFlip();
		
		// esc�L�[����������I������
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;
		
		// fps��60�ɌŒ�
		while (GetNowHiPerformanceCount() - time < 16667)
		{

		}
	
	}
	
		DxLib_End();		// DX���C�u�����g�p�̏I������

					

		return 0;	// �\�t�g�̏I��
	}
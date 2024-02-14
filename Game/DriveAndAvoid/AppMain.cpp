/**************************
*�Ԕ����Q�[��������Ă݂悤
***************************/
#include"DxLib.h"
#include"Scene/SceneManager.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

//���C���֐�(�v���O�����͂�������n�܂�܂��B)
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_
	LPSTR lpCmdLine, _In_ int nshowCmd)
{
	/*SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);
	ChangeWindowMode(TRUE);*/

	//��O����(�ُ킪����������,catch���ɔ�т܂�)
	try
	{
		//�V�[���}�l�[�W���[�@�\�̐���
		SceneManager manager;

		//�V�[���}�l�[�W���[�@�\�̏�����
		manager.Initialize();

		//�V�[���}�l�[�W���[�@�\�̍X�V����
		manager.Update();
		
		//�V�[���}�l�[�W���[�@�\�̏I��������
		manager.Finalize();
	}
	catch (const char* err_log)
	{
		//�G���[�������e�̏o��
		OutputDebugString(err_log);

		//�G���[�I����ʒm
		return-1;
	}

	//����I����ʒm
	return 0;
}


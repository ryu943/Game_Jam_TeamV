#pragma once

//�V�[�����
enum eSceneType
{
	E_TITLE,
	E_MAIN,
	E_HELP,
	E_RANKING_DISP,
	E_RANKING_INPUT,
	E_RESULT,
	E_END_SCENE,
	E_END
};

//���V�[���N���X
class SceneBase
{
public:
	SceneBase(){}
	virtual~SceneBase(){}

	//����������
	virtual void Initialize(){}
	//�X�V����
	virtual eSceneType Update()
	{
		return GetNowScene();
	}
	//�`�揈��
	virtual void Draw() const{}
	//�I��������
	virtual void Finalize(){}

	//���݂̃V�[�������擾
	virtual eSceneType GetNowScene() const = 0;
};
#pragma once

#include"SceneBase.h"
#include <ctime>

class TitleScene : public SceneBase
{

private:
	int background_image; //�w�i�摜
	int menu_image; //���j���[�摜
	int cursor_image; //�J�[�\���摜
	int menu_cursor; //���j���[�J�[�\���ԍ�

	int TitleBGM;
	int DecisionSE;
	int SelectSE;

	std::clock_t cursor_selected_time;

	const double transition_delay = 0.1;
public:
	TitleScene();
	virtual~TitleScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;
};
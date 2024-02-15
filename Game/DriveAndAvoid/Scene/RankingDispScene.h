#pragma once
#include"SceneBase.h"
#include"../Object/RankingData.h"

class RankingDispScene : public SceneBase
{

private:
	int background_image; //�w�i�摜
	RankingData* ranking; //�����L���O���
	int cursor;
	int title;
	int end;
	int select;
	bool Once;

	int TitleBGM;
	int DecisionSE;
	int SelectSE;

public:
	RankingDispScene();
	virtual~RankingDispScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;
};

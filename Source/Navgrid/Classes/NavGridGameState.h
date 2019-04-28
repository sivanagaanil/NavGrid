// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "GenericTeamAgentInterface.h"

#include "TurnManager.h"

#include "NavGridGameState.generated.h"

class ANavGrid;

/**
 *
 */
UCLASS()
class NAVGRID_API ANavGridGameState : public AGameStateBase
{
	GENERATED_BODY()
public:
	virtual void HandleBeginPlay() override;

	/* spawn the default turn manager object, override this if you need to modify it */
	virtual ATurnManager *SpawnTurnManager();
	/* spawn the default navgrid object, override this if you need to modify it */
	virtual ANavGrid *SpawnNavGrid();

	UPROPERTY(BlueprintReadWrite, VisibleAnyWhere, Category = "NavGrid")
	ANavGrid *Grid;

	UFUNCTION(BlueprintCallable, Category = "NavGrid")
	virtual ATurnManager *GetTurnManager() const { return TurnManager; }
	template <class T>
	T *GetTurnManager() const { return Cast<T>(GetTurnManager()); }

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnPawnEnterTile, class AGridPawn *, class UNavTileComponent *);
	FOnPawnEnterTile &OnPawnEnterTile() { return PawnEnterTileDelegate; }
private:
	FOnPawnEnterTile PawnEnterTileDelegate;

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnyWhere, Category = "NavGrid")
	ATurnManager *TurnManager;
};

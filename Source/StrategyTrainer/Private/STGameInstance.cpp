// Copyright Hexateam.


#include "STGameInstance.h"

#include "Kismet/GameplayStatics.h"

TArray<AActor*> USTGameInstance::SortByDistance(UObject* WorldContextObject, TArray<AActor*> Actors)
{
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(WorldContextObject, 0);
    
    Actors.Sort([PlayerPawn](const AActor& A, const AActor& B) {
        float DistA = FVector::Dist(A.GetActorLocation(), PlayerPawn->GetActorLocation());
        float DistB = FVector::Dist(B.GetActorLocation(), PlayerPawn->GetActorLocation());
        return DistA < DistB;
    });

    return Actors;
}

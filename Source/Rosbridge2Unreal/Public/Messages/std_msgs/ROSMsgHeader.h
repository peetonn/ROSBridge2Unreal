// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Messages/ROSMessageBase.h"
#include "ROSMsgHeader.generated.h"

UCLASS(BlueprintType)
class ROSBRIDGE2UNREAL_API UROSMsgHeader : public UROSMessageBase
{
	GENERATED_BODY()

public:
	/* Construction */
	UROSMsgHeader(){};
	UFUNCTION(BlueprintCallable, BlueprintPure) FString GetMessageType() override {return "std_msgs/Header";};
	UFUNCTION(BlueprintCallable, BlueprintPure) static UROSMsgHeader* CreateWithGeneratedTimeStamp(FString FrameID, int64 SequenceID);
	UFUNCTION(BlueprintCallable, BlueprintPure) static UROSMsgHeader* Create(FString FrameID, int64 SequenceID, int32 Seconds, int32 NanoSeconds);
	
	/* Data */
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int64 SequenceID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Seconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 NanoSeconds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FString FrameID;

	/* Transformation Functions */
	void ToData(ROSData& Message) const override;
	bool FromData(const ROSData& Message) override;
};

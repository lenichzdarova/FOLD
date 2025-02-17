#pragma once

class GameLog
{
	static TArray<FText> Log;
	static UUserWidget* Widget;
public:
	static void LogMessage(FText);
	static void SetLogWidget(UUserWidget*);
	
	DECLARE_MULTICAST_DELEGATE(FLogUpdated)
	static FLogUpdated Updated;
};

UUserWidget* GameLog::Widget = nullptr;



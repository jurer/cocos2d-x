using OpenXLive;
using OpenXLive.Silverlight;
using OpenXLive.Features;
using PhoneDirect3DXamlAppComponent.OpenXLiveHelper;
using System;
using System.Threading.Tasks;
using System.Windows;


namespace PhoneDirect3DXamlAppComponent
{
    /// <summary>
    /// A callback class that implements the WinRT Component interface ICallback.
    /// All methods provided will be called throught the ICallback interface in native code.
    /// </summary>
    public class XLiveCallback : ICallback
    {
        public event EventHandler<CompletedEventArgs> OnAwardComplted;
        public event EventHandler<CompletedEventArgs> OnSubmitCompleted;

        public async void Leaderboard_Submit(string leaderboardKey, int score)
        {
            await System.Threading.Tasks.Task.Run(async () =>
            {
                await Windows.ApplicationModel.Core.CoreApplication.MainView.CoreWindow.Dispatcher.RunAsync(
                Windows.UI.Core.CoreDispatcherPriority.Normal, () =>
                {
                    //Leaderboard lb = new Leaderboard(XLiveGameManager.CurrentSession, leaderboardKey);
                    //System.Threading.Thread.Sleep(5000);
                    //lb.SubmitScoreCompleted += new AsyncEventHandler(lb_SubmitScoreCompleted);
                    //lb.SubmitScore(score);
                    testAction();
                });
            });
            
            //Leaderboard lb = new Leaderboard(XLiveGameManager.CurrentSession, leaderboardKey);
            //System.Threading.Thread.Sleep(5000);
            //lb.SubmitScoreCompleted += new AsyncEventHandler(lb_SubmitScoreCompleted);
            //lb.SubmitScore(score);         
        }

        void lb_SubmitScoreCompleted(object sender, AsyncEventArgs e)
        {
            if (OnSubmitCompleted != null)
            {
                OnSubmitCompleted(sender, new CompletedEventArgs(e.Result.ReturnValue, e.Result.ErrorCode, e.Result.ErrorMessage));
            }
        }

        public void Achievement_Award(string achievementKey)
        {
            Achievement ac = new Achievement(XLiveGameManager.CurrentSession, achievementKey);
            ac.AwardCompleted += new AsyncEventHandler(ac_AwardCompleted);
            ac.Award();
        }

        void ac_AwardCompleted(object sender, AsyncEventArgs e)
        {
            if (OnAwardComplted != null)
            {
                OnAwardComplted(sender, new CompletedEventArgs(e.Result.ReturnValue, e.Result.ErrorCode, e.Result.ErrorMessage));
            }
        }
    }
}
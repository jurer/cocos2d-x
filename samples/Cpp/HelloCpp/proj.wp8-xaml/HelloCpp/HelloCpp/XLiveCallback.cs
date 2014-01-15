using OpenXLive;
using OpenXLive.Silverlight;
using OpenXLive.Features;
using PhoneDirect3DXamlAppComponent.OpenXLiveHelper;
using System;
using System.Threading.Tasks;
using System.Windows;
using Microsoft.Phone.Controls;

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
        private Direct3DInterop m_d3dInterop = null;
        private PhoneApplicationPage m_MainPage = null;

        public void SetDirect3DInterop(Direct3DInterop d3dInterop)
        {
            m_d3dInterop = d3dInterop;
        }

        public void SetMainPage(PhoneApplicationPage mainPage)
        {
            m_MainPage = mainPage;
        }

        private void CallToShowPage()
        {
            // get the UI thread (ie. the Main Thread) to let the worker thread (ie. opengl thread) work normally.
            Deployment.Current.Dispatcher.BeginInvoke(() =>
            {
                m_MainPage.NavigationService.Navigate(new Uri("/Page1.xaml", UriKind.Relative));
            });
        }

        public async void Leaderboard_Submit(string leaderboardKey, int score)
        {
            // get the UI thread (ie. the Main Thread) to let the worker thread (ie. opengl thread) work normally.
            Deployment.Current.Dispatcher.BeginInvoke(() =>
            {
                System.Threading.Thread.Sleep(5000);
                Leaderboard lb = new Leaderboard(XLiveGameManager.CurrentSession, leaderboardKey);
                lb.SubmitScoreCompleted += new AsyncEventHandler(lb_SubmitScoreCompleted);
                lb.SubmitScore(score);
            });
            
            //common worker thread
            //System.Threading.Tasks.Task.Run(async () =>
            //{
            //    System.Threading.Thread.Sleep(5000);
            //    Leaderboard lb = new Leaderboard(XLiveGameManager.CurrentSession, leaderboardKey);
            //    lb.SubmitScoreCompleted += new AsyncEventHandler(lb_SubmitScoreCompleted);
            //    lb.SubmitScore(score);  
            //});
        }

        void lb_SubmitScoreCompleted(object sender, AsyncEventArgs e)
        {
            if (OnSubmitCompleted != null)
            {
                m_d3dInterop.OnOpenXliveEvent(sender, new CompletedEventArgs(e.Result.ReturnValue, e.Result.ErrorCode, e.Result.ErrorMessage), OnSubmitCompleted);
            }
        }

        public void Achievement_Award(string achievementKey)
        {
            // get the UI thread (ie. the Main Thread) to let the worker thread (ie. opengl thread) work normally.
            Deployment.Current.Dispatcher.BeginInvoke(() =>
            {
                Achievement ac = new Achievement(XLiveGameManager.CurrentSession, achievementKey);
                ac.AwardCompleted += new AsyncEventHandler(ac_AwardCompleted);
                ac.Award();
            });
        }

        void ac_AwardCompleted(object sender, AsyncEventArgs e)
        {
            if (OnAwardComplted != null)
            {
                m_d3dInterop.OnOpenXliveEvent(sender, new CompletedEventArgs(e.Result.ReturnValue, e.Result.ErrorCode, e.Result.ErrorMessage), OnAwardComplted);
            }
        }

        public void ShowLogon()
        {
            // get the UI thread (ie. the Main Thread) to let the worker thread (ie. opengl thread) work normally.
            Deployment.Current.Dispatcher.BeginInvoke(() =>
            {
                XLiveUIManager.ShowLogon(); 
            });
        }
    }
}
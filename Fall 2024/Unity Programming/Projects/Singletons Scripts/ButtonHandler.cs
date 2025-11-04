using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class ButtonHandler : MonoBehaviour
{
    public AudioClip backgroundMusicClip;
    public AudioClip playerSoundClip;
    public AudioClip worldSoundClip;

    public void PlayBackgroundSound()
    {
        AudioManager.Instance.PlayBackgroundMusic(backgroundMusicClip);
    }
    
    public void PlayPlayerSound()
    {
        AudioManager.Instance.PlayPlayerSoundEffect(playerSoundClip);
    }
    
    public void PlayWorldSound()
    {
        AudioManager.Instance.PlayWorldSoundEffect(worldSoundClip);
    }

    public void SwitchScenes()
    {
        Scene currentScene = SceneManager.GetActiveScene();

        
        string sceneName = currentScene.name;

        if (sceneName == "Demo")
        {
            SceneManager.LoadScene("Scene2");
        }
        else
        {
            SceneManager.LoadScene("Demo");
        }
    }

    public void QuitGame()
    {
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#endif
        Application.Quit();
    }
}

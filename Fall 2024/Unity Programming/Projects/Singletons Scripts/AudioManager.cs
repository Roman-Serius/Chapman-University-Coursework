using UnityEngine;
using UnityEngine.SceneManagement;

public class AudioManager : MonoBehaviour
{
    public static AudioManager Instance;

    [SerializeField] private AudioSource backgroundMusic;
    [SerializeField] private AudioSource playerSound;
    [SerializeField] private AudioSource worldSound;

    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject); // Keep this object when switching scenes
        }
        else
        {
            Destroy(gameObject); // Destroy duplicates
        }
    }

    private void OnEnable()
    {
        SceneManager.sceneLoaded += OnSceneLoaded;
    }

    private void OnDisable()
    {
        SceneManager.sceneLoaded -= OnSceneLoaded;
    }

    // This will be called whenever a scene is loaded
    private void OnSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        // Example of reassigning AudioSource references after switching scenes
        if (worldSound == null)
        {
            worldSound = GameObject.FindWithTag("WorldSoundSource")?.GetComponent<AudioSource>();
            if (worldSound == null)
            {
                Debug.LogWarning("WorldSound AudioSource not found in the new scene!");
            }
        }

        if (playerSound == null)
        {
            playerSound = GameObject.FindWithTag("PlayerSoundSource")?.GetComponent<AudioSource>();
            if (playerSound == null)
            {
                Debug.LogWarning("PlayerSound AudioSource not found in the new scene!");
            }
        }

        if (backgroundMusic == null)
        {
            backgroundMusic = GameObject.FindWithTag("BackgroundMusicSource")?.GetComponent<AudioSource>();
            if (backgroundMusic == null)
            {
                Debug.LogWarning("BackgroundMusic AudioSource not found in the new scene!");
            }
        }
    }

    // Play background music with a null check
    public void PlayBackgroundMusic(AudioClip clip)
    {
        if (backgroundMusic != null)
        {
            backgroundMusic.clip = clip;
            backgroundMusic.Play();
        }
        else
        {
            Debug.LogWarning("Background music AudioSource is missing!");
        }
    }

    // Play player sound effect with a null check
    public void PlayPlayerSoundEffect(AudioClip clip)
    {
        if (playerSound != null)
        {
            playerSound.clip = clip;
            playerSound.Play();
        }
        else
        {
            Debug.LogWarning("Player sound AudioSource is missing!");
        }
    }

    // Play world sound effect with a null check
    public void PlayWorldSoundEffect(AudioClip clip)
    {
        if (worldSound != null)
        {
            worldSound.clip = clip;
            worldSound.Play();
        }
        else
        {
            Debug.LogWarning("World sound AudioSource is missing!");
        }
    }
}

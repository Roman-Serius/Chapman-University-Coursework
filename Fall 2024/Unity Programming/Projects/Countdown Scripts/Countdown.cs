//Soren Marius
// 002456139
// Marius@chapman.edu
// GAME-245-02
// Assignment1

using System.Collections;
using System.Collections.Generic;
using UnityEngine;




public class Countdown : MonoBehaviour
{
  public UpdateText UpdateText;


  //Called by GameManager
  public void StartCountdown()
  {
    StartCoroutine(CountdownTimer());
  }
  private IEnumerator CountdownTimer()
  {
    int count = 5;

    while (count > 0)
    {
      Debug.Log(count);
      UpdateText.TextEdit(count.ToString());
      count--;
      yield return new WaitForSeconds(1f);
    }
    UpdateText.TextEdit("GO!");
    yield return new WaitForSeconds(1f);
    UpdateText.TextEdit("");
    
  }
}

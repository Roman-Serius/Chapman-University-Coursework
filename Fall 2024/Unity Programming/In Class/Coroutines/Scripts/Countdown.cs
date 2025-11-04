using System.Collections;
using System.Collections.Generic;
using UnityEngine;



public class Countdown : MonoBehaviour
{
  public UpdateText UpdateText;


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
    UpdateText.TextEdit(""); //Makes the text "Disappear"
    
  }
}

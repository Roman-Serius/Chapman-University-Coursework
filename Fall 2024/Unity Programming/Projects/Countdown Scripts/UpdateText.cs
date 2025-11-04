//Soren Marius
// 002456139
// Marius@chapman.edu
// GAME-245-02
// Assignment1


using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using TMPro;

public class UpdateText : MonoBehaviour
{
   
   public TMP_Text Text;
   
   //Countdown calls this

   public void TextEdit(string newText)
   {
      Text.SetText(newText);
   }

 

  
}

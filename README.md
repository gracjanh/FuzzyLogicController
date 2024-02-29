1.  Inputs (temperature and light sensitivity) that represent crisp values are fuzzified. This operation involves classifying them into appropriate fuzzy sets based on the calculated degree of membership.

![image](https://github.com/gracjanh/FuzzyLogicController/assets/74767350/c61fdf8c-5ae8-49ac-b0ef-298fee191cc8)

2. Logical rules are created. Each rule consists of the words "if" and "then", specifying the set of conditions and the conclusion.

<table align="center">
    <tr>
        <th></th>
        <th align="center">DARK</th>
        <th align="center">BRIGHT</th>
        <th align="center">VERY BRIGHT</th>
    </tr>
    <tr>
        <th align="center">COLD</th>
        <td align="center">NONE</td>
        <td align="center">NONE</td>
        <td align="center">NONE</td>
    </tr>
    <tr>
        <th align="center">WARM</th>
        <td align="center">SLOW</td>
        <td align="center">SLOW</td>
        <td align="center">FAST</td>
    </tr>
    <tr>
        <th align="center">HOT</th>
        <td align="center">SLOW</td>
        <td align="center">FAST</td>
        <td align="center">FAST</td>
    </tr>
</table>

<div align="center">
  
  IF **COLD** AND **DARK** THEN **NONE** <br>
  IF **COLD** AND **BRIGHT** THEN **NONE** <br>
  IF **COLD** AND **VERY BRIGHT** THEN **NONE**
  
  IF **WARM** AND **DARK** THEN **SLOW** <br>
  IF **WARM** AND **BRIGHT** THEN **SLOW** <br>
  IF **WARM** AND **VERY BRIGHT** THEN **FAST**
  
  IF **HOT** AND **DARK** THEN **SLOW** <br>
  IF **HOT** AND **BRIGHT** THEN **FAST** <br>
  IF **HOT** AND **VERY BRIGHT** THEN **FAST**
  
</div>

3. The output value is sharpened.

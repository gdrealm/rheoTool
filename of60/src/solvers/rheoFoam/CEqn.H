   // Transport of passive scalar

    dimensionedScalar  D_ = cttProperties.subDict("passiveScalarProperties").lookup("D");
     
    fvScalarMatrix CEqn
    (
        fvm::ddt(C()) 
      + fvm::div(phi, C())
      ==
        fvm::laplacian(D_, C())    
      + fvOptions(C())  
    );

    CEqn.relax();
    fvOptions.constrain(CEqn);
    CEqn.solve();
    fvOptions.correct(C());
 

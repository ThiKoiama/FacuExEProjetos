import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ModalViewMateriaComponent } from './modal-view-materia.component';

describe('ModalViewMateriaComponent', () => {
  let component: ModalViewMateriaComponent;
  let fixture: ComponentFixture<ModalViewMateriaComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ModalViewMateriaComponent]
    })
    .compileComponents();
    
    fixture = TestBed.createComponent(ModalViewMateriaComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
